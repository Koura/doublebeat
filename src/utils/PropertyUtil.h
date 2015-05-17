#ifndef PROPERTYUTIL_H
#define	PROPERTYUTIL_H
#include <string>
#include <stdlib.h>

class PropertyUtil {
public:
    static std::string readValue(std::string key);
    static double readDouble(std::string key);
    static void initValues();
    static double getM2P();

    
private:
    static void setM2P();
  
    static double m2p;
};

#endif

