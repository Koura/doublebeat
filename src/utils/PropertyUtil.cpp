#include "PropertyUtil.h"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/ini_parser.hpp"

const std::string filename = "game.ini";

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

double PropertyUtil::readDouble(std::string key) {
    return atof(readValue(key).c_str());
}

void PropertyUtil::initValues() {
    PropertyUtil::m2p = readDouble("world.m2p");
}

double PropertyUtil::getM2P() {
    return PropertyUtil::m2p;
}

double PropertyUtil::m2p = 1;