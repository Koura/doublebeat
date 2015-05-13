#ifndef PROPERTYUTIL_H
#define	PROPERTYUTIL_H
#include <string>
#include <stdlib.h>

class PropertyUtil
{
public:
    static std::string readValue(std::string key);
    static double readDouble(std::string key);
};

#endif

