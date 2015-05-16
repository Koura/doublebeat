
#include <GL/gl.h>
#include <string.h>

#include "glDraw.h"

glDraw::drawSimpleTriangle(float x, float y, float red, float green, float blue, float size) {

    glPushMatrix();

    glBegin(GL_TRIANGLES);

    glColor4f(red, green, blue, 1);
    glVertex2f(x, size + y);
    glVertex2f(-size + x, -size + y);
    glVertex2f(size + x, -size + y);

    glEnd();

    glPopMatrix();
}

glDraw::drawSprite(float x, float y, std::string fileName) {
    
}

glDraw::drawText(float stx, float sty, char* str) {
    float x = stx;
    float y = sty;
    int len = strlen(str);
    
    glPushMatrix();
    
    glBegin(GL_POINTS);
    glColor4f(1, 1, 1, 1);
    for (int i = 0; i < len; i++) {
        char c = tolower(str[i]);
        if (c == 'a') {
            for (int i = 0; i < 8; i++) {
                glVertex2f(x + 1, y + i);
                glVertex2f(x + 7, y + i);
            }
            for (int i = 2; i <= 6; i++) {
                glVertex2f(x + i, y + 8);
                glVertex2f(x + i, y + 4);
            }
            x += 8;
        } else if (c == 'b') {
            for (int i = 0; i < 8; i++) {
                glVertex2f(x + 1, y + i);
            }
            for (int i = 1; i <= 6; i++) {
                glVertex2f(x + i, y);
                glVertex2f(x + i, y + 4);
                glVertex2f(x + i, y + 8);
            }
            glVertex2f(x + 7, y + 5);
            glVertex2f(x + 7, y + 7);
            glVertex2f(x + 7, y + 6);

            glVertex2f(x + 7, y + 1);
            glVertex2f(x + 7, y + 2);
            glVertex2f(x + 7, y + 3);
            x += 8;
        } else if (c == 'c') {
            for (int i = 1; i <= 7; i++) {
                glVertex2f(x + 1, y + i);
            }
            for (int i = 2; i <= 5; i++) {
                glVertex2f(x + i, y);
                glVertex2f(x + i, y + 8);
            }
            glVertex2f(x + 6, y + 1);
            glVertex2f(x + 6, y + 2);

            glVertex2f(x + 6, y + 6);
            glVertex2f(x + 6, y + 7);

            x += 8;
        } else if (c == 'd') {
            for (int i = 0; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
            }
            for (int i = 2; i <= 5; i++) {
                glVertex2f(x + i, y);
                glVertex2f(x + i, y + 8);
            }
            glVertex2f(x + 6, y + 1);
            glVertex2f(x + 6, y + 2);
            glVertex2f(x + 6, y + 3);
            glVertex2f(x + 6, y + 4);
            glVertex2f(x + 6, y + 5);
            glVertex2f(x + 6, y + 6);
            glVertex2f(x + 6, y + 7);

            x += 8;
        } else if (c == 'e') {
            for (int i = 0; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
            }
            for (int i = 1; i <= 6; i++) {
                glVertex2f(x + i, y + 0);
                glVertex2f(x + i, y + 8);
            }
            for (int i = 2; i <= 5; i++) {
                glVertex2f(x + i, y + 4);
            }
            x += 8;
        } else if (c == 'f') {
            for (int i = 0; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
            }
            for (int i = 1; i <= 6; i++) {
                glVertex2f(x + i, y + 8);
            }
            for (int i = 2; i <= 5; i++) {
                glVertex2f(x + i, y + 4);
            }
            x += 8;
        } else if (c == 'g') {
            for (int i = 1; i <= 7; i++) {
                glVertex2f(x + 1, y + i);
            }
            for (int i = 2; i <= 5; i++) {
                glVertex2f(x + i, y);
                glVertex2f(x + i, y + 8);
            }
            glVertex2f(x + 6, y + 1);
            glVertex2f(x + 6, y + 2);
            glVertex2f(x + 6, y + 3);
            glVertex2f(x + 5, y + 3);
            glVertex2f(x + 7, y + 3);

            glVertex2f(x + 6, y + 6);
            glVertex2f(x + 6, y + 7);

            x += 8;
        } else if (c == 'h') {
            for (int i = 0; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
                glVertex2f(x + 7, y + i);
            }
            for (int i = 2; i <= 6; i++) {
                glVertex2f(x + i, y + 4);
            }
            x += 8;
        } else if (c == 'i') {
            for (int i = 0; i <= 8; i++) {
                glVertex2f(x + 3, y + i);
            }
            for (int i = 1; i <= 5; i++) {
                glVertex2f(x + i, y + 0);
                glVertex2f(x + i, y + 8);
            }
            x += 7;
        } else if (c == 'j') {
            for (int i = 1; i <= 8; i++) {
                glVertex2f(x + 6, y + i);
            }
            for (int i = 2; i <= 5; i++) {
                glVertex2f(x + i, y + 0);
            }
            glVertex2f(x + 1, y + 3);
            glVertex2f(x + 1, y + 2);
            glVertex2f(x + 1, y + 1);
            x += 8;
        } else if (c == 'k') {
            for (int i = 0; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
            }
            glVertex2f(x + 6, y + 8);
            glVertex2f(x + 5, y + 7);
            glVertex2f(x + 4, y + 6);
            glVertex2f(x + 3, y + 5);
            glVertex2f(x + 2, y + 4);
            glVertex2f(x + 2, y + 3);
            glVertex2f(x + 3, y + 4);
            glVertex2f(x + 4, y + 3);
            glVertex2f(x + 5, y + 2);
            glVertex2f(x + 6, y + 1);
            glVertex2f(x + 7, y);
            x += 8;
        } else if (c == 'l') {
            for (int i = 0; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
            }
            for (int i = 1; i <= 6; i++) {
                glVertex2f(x + i, y);
            }
            x += 7;
        } else if (c == 'm') {
            for (int i = 0; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
                glVertex2f(x + 7, y + i);
            }
            glVertex2f(x + 3, y + 6);
            glVertex2f(x + 2, y + 7);
            glVertex2f(x + 4, y + 5);

            glVertex2f(x + 5, y + 6);
            glVertex2f(x + 6, y + 7);
            glVertex2f(x + 4, y + 5);
            x += 8;
        } else if (c == 'n') {
            for (int i = 0; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
                glVertex2f(x + 7, y + i);
            }
            glVertex2f(x + 2, y + 7);
            glVertex2f(x + 2, y + 6);
            glVertex2f(x + 3, y + 5);
            glVertex2f(x + 4, y + 4);
            glVertex2f(x + 5, y + 3);
            glVertex2f(x + 6, y + 2);
            glVertex2f(x + 6, y + 1);
            x += 8;
        } else if (c == 'o' || c == '0') {
            for (int i = 1; i <= 7; i++) {
                glVertex2f(x + 1, y + i);
                glVertex2f(x + 7, y + i);
            }
            for (int i = 2; i <= 6; i++) {
                glVertex2f(x + i, y + 8);
                glVertex2f(x + i, y + 0);
            }
            x += 8;
        } else if (c == 'p') {
            for (int i = 0; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
            }
            for (int i = 2; i <= 5; i++) {
                glVertex2f(x + i, y + 8);
                glVertex2f(x + i, y + 4);
            }
            glVertex2f(x + 6, y + 7);
            glVertex2f(x + 6, y + 5);
            glVertex2f(x + 6, y + 6);
            x += 8;
        } else if (c == 'q') {
            for (int i = 1; i <= 7; i++) {
                glVertex2f(x + 1, y + i);
                if (i != 1) {
                    glVertex2f(x + 7, y + i);
                }
            }
            for (int i = 2; i <= 6; i++) {
                glVertex2f(x + i, y + 8);
                if (i != 6) {
                    glVertex2f(x + i, y + 0);
                }
            }
            glVertex2f(x + 4, y + 3);
            glVertex2f(x + 5, y + 2);
            glVertex2f(x + 6, y + 1);
            glVertex2f(x + 7, y);
            x += 8;
        } else if (c == 'r') {
            for (int i = 0; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
            }
            for (int i = 2; i <= 5; i++) {
                glVertex2f(x + i, y + 8);
                glVertex2f(x + i, y + 4);
            }
            glVertex2f(x + 6, y + 7);
            glVertex2f(x + 6, y + 5);
            glVertex2f(x + 6, y + 6);

            glVertex2f(x + 4, y + 3);
            glVertex2f(x + 5, y + 2);
            glVertex2f(x + 6, y + 1);
            glVertex2f(x + 7, y);
            x += 8;
        } else if (c == 's') {
            for (int i = 2; i <= 7; i++) {
                glVertex2f(x + i, y + 8);
            }
            glVertex2f(x + 1, y + 7);
            glVertex2f(x + 1, y + 6);
            glVertex2f(x + 1, y + 5);
            for (int i = 2; i <= 6; i++) {
                glVertex2f(x + i, y + 4);
                glVertex2f(x + i, y);
            }
            glVertex2f(x + 7, y + 3);
            glVertex2f(x + 7, y + 2);
            glVertex2f(x + 7, y + 1);
            glVertex2f(x + 1, y + 1);
            glVertex2f(x + 1, y + 2);
            x += 8;
        } else if (c == 't') {
            for (int i = 0; i <= 8; i++) {
                glVertex2f(x + 4, y + i);
            }
            for (int i = 1; i <= 7; i++) {
                glVertex2f(x + i, y + 8);
            }
            x += 7;
        } else if (c == 'u') {
            for (int i = 1; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
                glVertex2f(x + 7, y + i);
            }
            for (int i = 2; i <= 6; i++) {
                glVertex2f(x + i, y + 0);
            }
            x += 8;
        } else if (c == 'v') {
            for (int i = 2; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
                glVertex2f(x + 6, y + i);
            }
            glVertex2f(x + 2, y + 1);
            glVertex2f(x + 5, y + 1);
            glVertex2f(x + 3, y);
            glVertex2f(x + 4, y);
            x += 7;
        } else if (c == 'w') {
            for (int i = 1; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
                glVertex2f(x + 7, y + i);
            }
            glVertex2f(x + 2, y);
            glVertex2f(x + 3, y);
            glVertex2f(x + 5, y);
            glVertex2f(x + 6, y);
            for (int i = 1; i <= 6; i++) {
                glVertex2f(x + 4, y + i);
            }
            x += 8;
        } else if (c == 'x') {
            for (int i = 1; i <= 7; i++) {
                glVertex2f(x + i, y + i);
            }
            for (int i = 7; i >= 1; i--) {
                glVertex2f(x + i, y + 8 - i);
            }
            x += 8;
        } else if (c == 'y') {
            glVertex2f(x + 4, y);
            glVertex2f(x + 4, y + 1);
            glVertex2f(x + 4, y + 2);
            glVertex2f(x + 4, y + 3);
            glVertex2f(x + 4, y + 4);

            glVertex2f(x + 3, y + 5);
            glVertex2f(x + 2, y + 6);
            glVertex2f(x + 1, y + 7);
            glVertex2f(x + 1, y + 8);

            glVertex2f(x + 5, y + 5);
            glVertex2f(x + 6, y + 6);
            glVertex2f(x + 7, y + 7);
            glVertex2f(x + 7, y + 8);
            x += 8;
        } else if (c == 'z') {
            for (int i = 1; i <= 6; i++) {
                glVertex2f(x + i, y);
                glVertex2f(x + i, y + 8);
                glVertex2f(x + i, y + i);
            }
            glVertex2f(x + 6, y + 7);
            x += 8;
        } else if (c == '1') {
            for (int i = 2; i <= 6; i++) {
                glVertex2f(x + i, y);
            }
            for (int i = 1; i <= 8; i++) {
                glVertex2f(x + 4, y + i);
            }
            glVertex2f(x + 3, y + 7);
            x += 8;
        } else if (c == '2') {
            for (int i = 1; i <= 6; i++) {
                glVertex2f(x + i, y);
            }
            for (int i = 2; i <= 5; i++) {
                glVertex2f(x + i, y + 8);
            }
            glVertex2f(x + 1, y + 7);
            glVertex2f(x + 1, y + 6);

            glVertex2f(x + 6, y + 7);
            glVertex2f(x + 6, y + 6);
            glVertex2f(x + 6, y + 5);
            glVertex2f(x + 5, y + 4);
            glVertex2f(x + 4, y + 3);
            glVertex2f(x + 3, y + 2);
            glVertex2f(x + 2, y + 1);
            x += 8;
        } else if (c == '3') {
            for (int i = 1; i <= 5; i++) {
                glVertex2f(x + i, y + 8);
                glVertex2f(x + i, y);
            }
            for (int i = 1; i <= 7; i++) {
                glVertex2f(x + 6, y + i);
            }
            for (int i = 2; i <= 5; i++) {
                glVertex2f(x + i, y + 4);
            }
            x += 8;
        } else if (c == '4') {
            for (int i = 2; i <= 8; i++) {
                glVertex2f(x + 1, y + i);
            }
            for (int i = 2; i <= 7; i++) {
                glVertex2f(x + i, y + 1);
            }
            for (int i = 0; i <= 4; i++) {
                glVertex2f(x + 4, y + i);
            }
            x += 8;
        } else if (c == '5') {
            for (int i = 1; i <= 7; i++) {
                glVertex2f(x + i, y + 8);
            }
            for (int i = 4; i <= 7; i++) {
                glVertex2f(x + 1, y + i);
            }
            glVertex2f(x + 1, y + 1);
            glVertex2f(x + 2, y);
            glVertex2f(x + 3, y);
            glVertex2f(x + 4, y);
            glVertex2f(x + 5, y);
            glVertex2f(x + 6, y);

            glVertex2f(x + 7, y + 1);
            glVertex2f(x + 7, y + 2);
            glVertex2f(x + 7, y + 3);

            glVertex2f(x + 6, y + 4);
            glVertex2f(x + 5, y + 4);
            glVertex2f(x + 4, y + 4);
            glVertex2f(x + 3, y + 4);
            glVertex2f(x + 2, y + 4);
            x += 8;
        } else if (c == '6') {
            for (int i = 1; i <= 7; i++) {
                glVertex2f(x + 1, y + i);
            }
            for (int i = 2; i <= 6; i++) {
                glVertex2f(x + i, y);
            }
            for (int i = 2; i <= 5; i++) {
                glVertex2f(x + i, y + 4);
                glVertex2f(x + i, y + 8);
            }
            glVertex2f(x + 7, y + 1);
            glVertex2f(x + 7, y + 2);
            glVertex2f(x + 7, y + 3);
            glVertex2f(x + 6, y + 4);
            x += 8;
        } else if (c == '7') {
            for (int i = 0; i <= 7; i++) {
                glVertex2f(x + i, y + 8);
            }
            glVertex2f(x + 7, y + 7);
            glVertex2f(x + 7, y + 6);

            glVertex2f(x + 6, y + 5);
            glVertex2f(x + 5, y + 4);
            glVertex2f(x + 4, y + 3);
            glVertex2f(x + 3, y + 2);
            glVertex2f(x + 2, y + 1);
            glVertex2f(x + 1, y);
            x += 8;
        } else if (c == '8') {
            for (int i = 1; i <= 7; i++) {
                glVertex2f(x + 1, y + i);
                glVertex2f(x + 7, y + i);
            }
            for (int i = 2; i <= 6; i++) {
                glVertex2f(x + i, y + 8);
                glVertex2f(x + i, y + 0);
            }
            for (int i = 2; i <= 6; i++) {
                glVertex2f(x + i, y + 4);
            }
            x += 8;
        } else if (c == '9') {
            for (int i = 1; i <= 7; i++) {
                glVertex2f(x + 7, y + i);
            }
            for (int i = 5; i <= 7; i++) {
                glVertex2f(x + 1, y + i);
            }
            for (int i = 2; i <= 6; i++) {
                glVertex2f(x + i, y + 8);
                glVertex2f(x + i, y + 0);
            }
            for (int i = 2; i <= 6; i++) {
                glVertex2f(x + i, y + 4);
            }
            glVertex2f(x + 1, y + 0);
            x += 8;
        } else if (c == '.') {
            glVertex2f(x + 1, y);
            x += 2;
        } else if (c == ',') {
            glVertex2f(x + 1, y);
            glVertex2f(x + 1, y + 1);
            x += 2;
        } else if (c == '\n') {
            y -= 10;
            x = stx;
        } else if (c == ' ') {
            x += 8;
        }
    }
    glEnd();
    
    glPopMatrix();
}

