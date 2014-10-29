/**
 * @file
 *
 * @author Frank Leveque
 * @brief Useful inline functions for the Matasano Crypto Challenge
 *
 */

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>
#include <sstream>
#include <iostream>

namespace Utility
{

//! returns string with char removed
inline std::string removeChar(std::string str, char ch)
{
    std::stringstream ss;
    ss.str("");
    for(unsigned int i=0; i < str.size(); ++i)
    {
        if(str[i] != ch)
            ss << str[i];
    }
    return (std::string)ss.str();
}

};
#endif
