
#include <GL/gl.h>

#include "glDraw.h"

glDraw::drawSimpleTriangle(float x, float y, float red, float green, float blue, float size) {
//    glPushMatrix();
//
//    glTranslatef(x, y, 0.0f);
//    
    glBegin(GL_TRIANGLES);
    
    glColor4f(red, green, blue, 1);
    glVertex2f(x, size+y);
    glVertex2f(-size+x, -size+y);
    glVertex2f(size+x, -size+y);
    
    glEnd();
    
//    glPopMatrix();
}

