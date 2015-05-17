#include "PropertyUtil.h"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/ini_parser.hpp"

const std::string filename = "game.ini";

//Reads value from game.ini where key is of form X.Y
//Here X is for example [world] in game.ini and Y is variables under this scope,
//such as m2p
std::string PropertyUtil::readValue(std::string key) {
    boost::property_tree::ptree pt;
    try {
        //
        boost::property_tree::ini_parser::read_ini(filename, pt);
    } catch (const boost::property_tree::ptree_error &e) {
        return "";
    }
    return pt.get<std::string>(key);
}

//Parses double value from the string value read in readValue
double PropertyUtil::readDouble(std::string key) {
    return atof(readValue(key).c_str());
}

//initializes meters to pixels variable
void PropertyUtil::initValues() {
    PropertyUtil::m2p = readDouble("world.m2p");
}
//get the variable that maps meters to pixels
double PropertyUtil::getM2P() {
    return PropertyUtil::m2p;
}

void PropertyUtil::incrementContacts() {
    numOfFootContacts++;
}

void PropertyUtil::decreaseContacts() {
    numOfFootContacts--;
}

//gets the number of contacts that hero has to boundary objects
int PropertyUtil::getContacts() {
    return numOfFootContacts;
}

double PropertyUtil::m2p = 1;
int PropertyUtil::numOfFootContacts = 0;