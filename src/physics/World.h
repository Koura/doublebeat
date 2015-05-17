#ifndef WORLD_H
#define	WORLD_H
#include "../draw/DebugDraw.h"
#include "../utils/PropertyUtil.h"
#include "ContactListener.h"
#include <Box2D/Box2D.h>
#include <stdio.h>

struct position {
    int x;
    int y;
};

class World {
public:
    World();
    ~World();
    bool init();
    void shutdown();
    void step();
    void reInit();
    void jump();
    void draw();
    position getHeroPosition();
    void createAttackHitBox();
    
private:
    void createHero();
    void destroyFixtures();

    DebugDraw debugDraw;
    ContactListener contactListener;

    b2World* m_world;
    b2Body* m_groundBody;
    b2Body* m_heroBody;
    b2Body* m_hitboxBody;
    
    b2Fixture* m_footSensorFixture;
    b2Fixture* m_hitbox;
    
    b2BodyDef m_groundBodyDef;
    b2PolygonShape m_groundBox;
    b2BodyDef m_bodyDef;
    b2PolygonShape m_dynamicBox;
    b2FixtureDef m_fixtureDef;
    b2Vec2 m_gravity;

    int32 velocityIterations;
    int32 positionIterations;
    int attackCooldown;
    float32 timeStep;
};

#endif	/* WORLD_H */

