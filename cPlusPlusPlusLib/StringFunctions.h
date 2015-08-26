/*
 * This is the header file for the StringFunctions class of cPlusPlusPlusLib
 * cPPPLib - A library of functions that should be in the C++ Standard Library
 * (C) - Charles Machalow - MIT License
 */

#ifndef StringFunctions_H
#define StringFunctions_H

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

/// <summary>
/// Class for functions relating to std::strings
/// </summary>
class StringFunctions
{
public:
	static std::vector<std::string> splitIntoVector(const std::string &original_str, const std::string &delim);
	static std::vector<std::string> splitIntoVector(const std::string &original_str, const std::vector<std::string> &delims);
	static std::vector<std::string> splitIntoVectorByWhitespace(const std::string &original_str);

	static std::string toTitleCase(const std::string &original_str);
	static std::string toUpperCase(const std::string &original_str);
	static std::string toLowerCase(const std::string &original_str);
	static std::string swapCase(const std::string &original_str);
	static std::string slice(const std::string &original_str, const std::string &slice_str);

	static bool isOnlyWhitespace(const std::string &original_str);

};

#endif StringFunctions_H