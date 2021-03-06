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
    static void incrementContacts();
    static void decreaseContacts();
    static int getContacts();

private:
    static void setM2P();
    //meters to pixels
    static double m2p;
    //amount of boundary objects the hero is colliding with
    static int numOfFootContacts;
};

#endif

