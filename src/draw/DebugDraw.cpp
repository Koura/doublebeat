/*
 * Copyright (c) 2006-2007 Erin Catto http://www.box2d.org
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

#include "DebugDraw.h"
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>

#include <cstdio>
#include <cstdarg>
#include <cstring>

void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINE_LOOP);
    for (int32 i = 0; i < vertexCount; ++i) {
        glVertex2f(vertices[i].x*m2p, vertices[i].y*m2p);
    }
    glEnd();
}

void DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.5f * color.r, 0.5f * color.g, 0.5f * color.b, 0.5f);
    glBegin(GL_TRIANGLE_FAN);
    for (int32 i = 0; i < vertexCount; ++i) {
        glVertex2f(vertices[i].x*m2p, vertices[i].y*m2p);
    }
    glEnd();
    glDisable(GL_BLEND);

    glColor4f(color.r, color.g, color.b, 1.0f);
    glBegin(GL_LINE_LOOP);
    for (int32 i = 0; i < vertexCount; ++i) {
        glVertex2f(vertices[i].x*m2p, vertices[i].y*m2p);
    }
    glEnd();
}

void DebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
    const float32 k_segments = 16.0f;
    const float32 k_increment = 2.0f * b2_pi / k_segments;
    float32 theta = 0.0f;
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINE_LOOP);
    for (int32 i = 0; i < k_segments; ++i) {
        b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
        glVertex2f(v.x*m2p, v.y*m2p);
        theta += k_increment;
    }
    glEnd();
}

void DebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
    const float32 k_segments = 16.0f;
    const float32 k_increment = 2.0f * b2_pi / k_segments;
    float32 theta = 0.0f;
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.5f * color.r, 0.5f * color.g, 0.5f * color.b, 0.5f);
    glBegin(GL_TRIANGLE_FAN);
    for (int32 i = 0; i < k_segments; ++i) {
        b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
        glVertex2f(v.x*m2p, v.y*m2p);
        theta += k_increment;
    }
    glEnd();
    glDisable(GL_BLEND);

    theta = 0.0f;
    glColor4f(color.r, color.g, color.b, 1.0f);
    glBegin(GL_LINE_LOOP);
    for (int32 i = 0; i < k_segments; ++i) {
        b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
        glVertex2f(v.x*m2p, v.y*m2p);
        theta += k_increment;
    }
    glEnd();

    b2Vec2 p = center + radius * axis;
    glBegin(GL_LINES);
    glVertex2f(center.x*m2p, center.y*m2p);
    glVertex2f(p.x*m2p, p.y*m2p);
    glEnd();
}

void DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINES);
    glVertex2f(p1.x*m2p, p1.y*m2p);
    glVertex2f(p2.x*m2p, p2.y*m2p);
    glEnd();
}

void DebugDraw::DrawTransform(const b2Transform& xf) {
    b2Vec2 p1 = xf.p, p2;
    const float32 k_axisScale = 0.4f;
    glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(p1.x*m2p, p1.y*m2p);
    p2 = p1 + k_axisScale * xf.q.GetXAxis();
    glVertex2f(p2.x*m2p, p2.y*m2p);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(p1.x*m2p, p1.y*m2p);
    p2 = p1 + k_axisScale * xf.q.GetYAxis();
    glVertex2f(p2.x*m2p, p2.y*m2p);

    glEnd();
}

void DebugDraw::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color) {
    glPointSize(size);
    glBegin(GL_POINTS);
    glColor3f(color.r, color.g, color.b);
    glVertex2f(p.x*m2p, p.y*m2p);
    glEnd();
    glPointSize(1.0f);
}

void DebugDraw::DrawString(int x, int y, const char *string, ...) {
    char buffer[128];

    va_list arg;
    va_start(arg, string);
    vsprintf(buffer, string, arg);
    va_end(arg);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    int w = 1366;
    int h = 768;

    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(0.9f, 0.6f, 0.6f);
    glRasterPos2i(x, y);
    int32 length = (int32) strlen(buffer);
    for (int32 i = 0; i < length; ++i) {
        //glutBitmapCharacter(GLUT_BITMAP_8_BY_13, buffer[i]);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void DebugDraw::DrawAABB(b2AABB* aabb, const b2Color& c) {
    glColor3f(c.r, c.g, c.b);
    glBegin(GL_LINE_LOOP);
    glVertex2f(aabb->lowerBound.x*m2p, aabb->lowerBound.y*m2p);
    glVertex2f(aabb->upperBound.x*m2p, aabb->lowerBound.y*m2p);
    glVertex2f(aabb->upperBound.x*m2p, aabb->upperBound.y*m2p);
    glVertex2f(aabb->lowerBound.x*m2p, aabb->upperBound.y*m2p);
    glEnd();
}

void DebugDraw::setM2P(double val) {
    m2p = val;
}
