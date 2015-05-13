#include "World.h"

World::World()
{
    m_world = nullptr;
    m_groundBody = nullptr;
    m_heroBody = nullptr;
}

World::~World()
{
}

bool World::init()
{
    m_gravity = b2Vec2(PropertyUtil::readDouble("gravity.horizontal"),
            PropertyUtil::readDouble("gravity.vertical"));
    m_world = new b2World(m_gravity);
    m_groundBodyDef.position.Set(PropertyUtil::readDouble("gravity.horizontal"), 
            PropertyUtil::readDouble("gravity.vertical"));
    m_groundBody = m_world->CreateBody(&m_groundBodyDef);
    m_groundBox.SetAsBox(50.0f, 10.0f);
    m_groundBody->CreateFixture(&m_groundBox, 0.0f);
    
    m_bodyDef.type = b2_dynamicBody;
    m_bodyDef.position.Set(0.0f, 4.0f);
    m_heroBody = m_world->CreateBody(&m_bodyDef);
    
    m_dynamicBox.SetAsBox(1.0f, 1.0f);
    m_fixtureDef.shape = &m_dynamicBox;
    m_fixtureDef.density = PropertyUtil::readDouble("hero.density");
    m_fixtureDef.friction = PropertyUtil::readDouble("hero.friction");
    
    m_heroBody->CreateFixture(&m_fixtureDef);
    
    timeStep = 1.0f/60.0f;
    velocityIterations =PropertyUtil::readDouble("world.velIter");
    positionIterations = PropertyUtil::readDouble("world.posIter");
    
    return true;
}

void World::shutdown() 
{
    if(m_heroBody)
    {
        m_world->DestroyBody(m_heroBody);
        m_heroBody = nullptr;
    }
    if(m_groundBody)
    {
        m_world->DestroyBody(m_groundBody);
        m_groundBody = nullptr;
    }
    if(m_world)
    {
        delete m_world;
        m_world = nullptr;
    }
}

void World::step() 
{
    m_world->Step(timeStep, velocityIterations, positionIterations);
    //printf("%4.2f %4.2f %4.2f\n", m_heroBody->GetPosition().x,  m_heroBody->GetPosition().y,  m_heroBody->GetAngle());
}

void World::reInit()
{
    m_gravity = b2Vec2(PropertyUtil::readDouble("gravity.horizontal"),
            PropertyUtil::readDouble("gravity.vertical"));
    m_world->SetGravity(m_gravity);
    m_groundBodyDef.position.Set(PropertyUtil::readDouble("gravity.horizontal"), 
            PropertyUtil::readDouble("gravity.vertical"));
    m_groundBox.SetAsBox(50.0f, 10.0f);
    m_bodyDef.position.Set(0.0f, 4.0f);
    
    m_dynamicBox.SetAsBox(1.0f, 1.0f);
    m_fixtureDef.shape = &m_dynamicBox;
    m_fixtureDef.density = 1.0f;
    m_fixtureDef.friction = 0.3f;
    
    timeStep = 1.0f/60.0f;
    velocityIterations = PropertyUtil::readDouble("world.velIter");
    positionIterations = PropertyUtil::readDouble("world.posIter");
}

void World::jump()
{
    float impulse = m_heroBody->GetMass() * PropertyUtil::readDouble("hero.jumppower");
    m_heroBody->ApplyLinearImpulse(b2Vec2(0,impulse), m_heroBody->GetWorldCenter(), true);
}