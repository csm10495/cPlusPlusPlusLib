/*
 * This is the main header file for cPlusPlusPlusLib
 * cPPPLib - A library of functions that should be in the C++ Standard Library
 * (C) - Charles Machalow - MIT License
 */

#ifndef cPPPLib_H
#define cPPPLib_H

#include <string>
#include <vector>
#include <iostream>

static const std::string cPPPLib_V = ".1Alpha";

/// <summary>
/// Class for functions relating to std::strings
/// </summary>
class StringFunctions
{
public:
	static std::vector<std::string> splitIntoVector(const std::string &original_str, const std::string &delim);
	static std::vector<std::string> splitIntoVectorByWhitespace(const std::string &original_str);
};

#endif cPPPLib_H