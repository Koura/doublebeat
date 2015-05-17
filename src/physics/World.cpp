#include <iostream>
#include "World.h"
#include "../draw/glDraw.h"

World::World() {
    m_world = nullptr;
    m_groundBody = nullptr;
    m_heroBody = nullptr;
    attackCooldown = 0;
    spawntimer = 0;
}

World::~World() {
}

bool World::init() {
    m_gravity = b2Vec2(PropertyUtil::readDouble("gravity.horizontal"),
            PropertyUtil::readDouble("gravity.vertical"));
    m_world = new b2World(m_gravity);
    m_groundBodyDef.position.Set(PropertyUtil::readDouble("gravity.horizontal"),
            PropertyUtil::readDouble("gravity.vertical"));
    m_groundBody = m_world->CreateBody(&m_groundBodyDef);
    m_groundBox.SetAsBox(PropertyUtil::readDouble("world.width"), PropertyUtil::readDouble("world.height"));
    m_groundBody->CreateFixture(&m_groundBox, 0.0f);

    createHero();

    timeStep = 1.0f / 60.0f;
    velocityIterations = PropertyUtil::readDouble("world.velIter");
    positionIterations = PropertyUtil::readDouble("world.posIter");

    m_world->SetDebugDraw(&debugDraw);
    debugDraw.SetFlags(b2Draw::e_shapeBit);
    debugDraw.setM2P(PropertyUtil::getM2P());
    m_world->SetContactListener(&contactListener);

    return true;
}

void World::shutdown() {
    if (m_hitboxBody) {
        m_world->DestroyBody(m_hitboxBody);
        m_hitboxBody = nullptr;
    }
    if (m_footSensorFixture) {
        m_heroBody->DestroyFixture(m_footSensorFixture);
        m_footSensorFixture = nullptr;
    }
    if (m_heroBody) {
        m_world->DestroyBody(m_heroBody);
        m_heroBody = nullptr;
    }
    if (m_groundBody) {
        m_world->DestroyBody(m_groundBody);
        m_groundBody = nullptr;
    }
    if (m_world) {
        destroyBodies();
        delete m_world;
        m_world = nullptr;
    }
}

void World::step() {
    m_world->Step(timeStep, velocityIterations, positionIterations);
    if(attackCooldown == 0) {
        if(m_hitboxBody) {
            m_world->DestroyBody(m_hitboxBody);
            m_hitboxBody = nullptr;
        }
    }
    if(spawntimer==0) {
        createEnemy();
    } else {
        spawntimer--;
    }
    if(attackCooldown>0) {
        attackCooldown--;
    }
    //printf("%4.2f %4.2f %4.2f\n", m_heroBody->GetPosition().x,  m_heroBody->GetPosition().y,  m_heroBody->GetAngle());
}

void World::reInit() {
    destroyFixtures();
    m_gravity = b2Vec2(PropertyUtil::readDouble("gravity.horizontal"),
            PropertyUtil::readDouble("gravity.vertical"));
    m_world->SetGravity(m_gravity);
    m_groundBodyDef.position.Set(PropertyUtil::readDouble("gravity.horizontal"),
            PropertyUtil::readDouble("gravity.vertical"));
    m_groundBox.SetAsBox(PropertyUtil::readDouble("world.width"), PropertyUtil::readDouble("world.height"));
    m_groundBody->CreateFixture(&m_groundBox, 0.0f);

    m_dynamicBox.SetAsBox(PropertyUtil::readDouble("hero.width"), PropertyUtil::readDouble("hero.height"));
    m_fixtureDef.shape = &m_dynamicBox;
    m_fixtureDef.density = 1.0f;
    m_fixtureDef.friction = 0.3f;
    m_heroBody->CreateFixture(&m_fixtureDef);
    timeStep = 1.0f / 60.0f;
    velocityIterations = PropertyUtil::readDouble("world.velIter");
    positionIterations = PropertyUtil::readDouble("world.posIter");
    debugDraw.setM2P(PropertyUtil::getM2P());
}

void World::jump() {
    if (!PropertyUtil::getContacts() < 1) {
        float impulse = m_heroBody->GetMass() * PropertyUtil::readDouble("hero.jumppower");
        m_heroBody->ApplyLinearImpulse(b2Vec2(0, impulse), m_heroBody->GetWorldCenter(), true);
    }
}

void World::draw() {
    glDraw::drawSimpleTriangle(m_heroBody->GetPosition().x, m_heroBody->GetPosition().y, 1.0f, 0.0f, 1.0f, 1.6f);
    m_world->DrawDebugData();
}

void World::destroyFixtures() {
    for (b2Fixture* f = m_groundBody->GetFixtureList(); f; f = f->GetNext()) {
        m_groundBody->DestroyFixture(f);
    }

    for (b2Fixture* f = m_heroBody->GetFixtureList(); f; f = f->GetNext()) {
        m_heroBody->DestroyFixture(f);
    }
}

void World::destroyBodies() {
    for (b2Body* b = m_world->GetBodyList(); b; b = b->GetNext()) {
        m_world->DestroyBody(b);
    }
}

position World::getHeroPosition() {
    position retVal = {0, 0};
    retVal.x = m_heroBody->GetPosition().x;
    retVal.y = m_heroBody->GetPosition().y;
    return retVal;
}

void World::createHero() {
    m_bodyDef.type = b2_dynamicBody;
    m_bodyDef.position.Set(0.0f, 0.0f);
    m_heroBody = m_world->CreateBody(&m_bodyDef);

    m_dynamicBox.SetAsBox(PropertyUtil::readDouble("hero.width"), PropertyUtil::readDouble("hero.height"));
    m_fixtureDef.shape = &m_dynamicBox;
    m_fixtureDef.density = PropertyUtil::readDouble("hero.density");
    m_fixtureDef.friction = PropertyUtil::readDouble("hero.friction");
    m_fixtureDef.filter.categoryBits = HERO;
    m_fixtureDef.filter.maskBits = BOUNDARY | ENEMY;
    m_heroBody->CreateFixture(&m_fixtureDef);

    m_dynamicBox.SetAsBox(0.3, 0.3, b2Vec2(0, -PropertyUtil::readDouble("hero.height")), 0);
    m_fixtureDef.isSensor = true;
    m_fixtureDef.filter.categoryBits = FEET;
    m_fixtureDef.filter.maskBits = BOUNDARY;
    
    m_footSensorFixture = m_heroBody->CreateFixture(&m_fixtureDef);
    m_footSensorFixture->SetUserData((void*) 1);
}

void World::createAttackHitBox() {
    if (attackCooldown == 0 && !m_hitboxBody) {
        m_bodyDef.type = b2_staticBody;
        m_bodyDef.position.Set(m_heroBody->GetWorldCenter().x + 1, m_heroBody->GetWorldCenter().y + 0.5);
        m_hitboxBody = m_world->CreateBody(&m_bodyDef);

        m_dynamicBox.SetAsBox(1, 0.3);
        m_fixtureDef.shape = &m_dynamicBox;

        m_hitboxBody->CreateFixture(&m_fixtureDef);
        attackCooldown = 30;
    }
}

void World::createEnemy() {
    m_bodyDef.type = b2_dynamicBody;
    m_bodyDef.position.Set(10, -2.5);
    m_enemyBody = m_world->CreateBody(&m_bodyDef);
    
    m_dynamicBox.SetAsBox(0.5,0.5);
    m_fixtureDef.shape = &m_dynamicBox;
    m_fixtureDef.filter.categoryBits = ENEMY;
    m_fixtureDef.filter.maskBits = HERO;
    m_enemyBody->CreateFixture(&m_fixtureDef);
    m_enemyBody->SetGravityScale(0);
    m_enemyBody->SetLinearVelocity(b2Vec2(-2,0));
    spawntimer = 120;
}