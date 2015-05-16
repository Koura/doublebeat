#ifndef GLDRAW_H
#define	GLDRAW_H
#include <string>
#include <stdlib.h>

class glDraw {
public:
    static drawSimpleTriangle(float x, float y, float red, float green, float blue, float size);
    static drawText(float x, float y, char* str);
    static drawSprite(float x, float y, std::string fileName);
private:

};

#endif	

