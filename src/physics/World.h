#ifndef WORLD_H
#define	WORLD_H
#include "../draw/DebugDraw.h"
#include "../utils/PropertyUtil.h"
#include <Box2D/Box2D.h>
#include <stdio.h>

class World
{
public:
    World();
    ~World();
    bool init();
    void shutdown();
    void step();
    void reInit();
    void jump();
    void draw();
    
private:
    DebugDraw debugDraw;
    
    b2World* m_world;
    b2Body* m_groundBody;
    b2Body* m_heroBody;
    
    b2BodyDef m_groundBodyDef;
    b2PolygonShape m_groundBox;
    b2BodyDef m_bodyDef;
    b2PolygonShape m_dynamicBox;
    b2FixtureDef m_fixtureDef;
    b2Vec2 m_gravity;
    
    int32 velocityIterations;
    int32 positionIterations;
    float32 timeStep;
};

#endif	/* WORLD_H */

