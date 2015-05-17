#ifndef GLDRAW_H
#define	GLDRAW_H
#include <string>
#include <stdlib.h>
#include "../utils/PropertyUtil.h"

class glDraw {
public:
    static drawSimpleTriangle(float x, float y, float red, float green, float blue, float size);
    static drawText(float x, float y, char* str);
    static drawTexture(float x, float y, char* fileName);
    static drawHPbar(float x, float y, float red, float green, float blue, float size);
private:

};

#endif	

