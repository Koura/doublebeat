#include "PropertyUtil.h"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/ini_parser.hpp"

std::string PropertyUtil::readValue(std::string file, std::string key)
{
    boost::property_tree::ptree pt;
   try
    {
       //
       boost::property_tree::ini_parser::read_ini(file, pt);
    } catch (const boost::property_tree::ptree_error &e)
    {
            return "";
    }
    return pt.get<std::string>(key);
}