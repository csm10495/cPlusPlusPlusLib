/*
* This is the cpp file for the StringFunctions class of cPlusPlusPlusLib
* cPPPLib - A library of functions that should be in the C++ Standard Library
* (C) - Charles Machalow - MIT License
*/

#ifndef StringFunctions_CPP
#define StringFunctions_CPP

#include "StringFunctions.h"

/// <summary>
/// Splits the original_str into a std::vector by delimiter
/// </summary>
/// <param name="original_str">The original_str.</param>
/// <param name="delim">The delimiter.</param>
/// <returns>std::vector<string> where each item is a string that has been delimited</returns>
std::vector<std::string> StringFunctions::splitIntoVector(const std::string &original_str, const std::string &delim)
{
	std::string working_str = original_str;
	std::vector<std::string> ret_vec;

	while (!working_str.empty())
	{
		unsigned int loc = working_str.find(delim);
		// found in string
		if (loc != std::string::npos)
		{
			ret_vec.push_back(working_str.substr(0, loc));
			working_str = working_str.substr(loc + 1);
		}
		else
		{
			ret_vec.push_back(working_str);
			break;
		}
	}

	return ret_vec;
}

/// <summary>
/// Splits the original_str into a std::vector by whitespace.
/// </summary>
/// <param name="original_str">The original_str.</param>
/// <returns>std::vector<string> where each item is a string that has been delimited by whitespace</returns>
std::vector<std::string> StringFunctions::splitIntoVectorByWhitespace(const std::string &original_str)
{
	std::string working_str = original_str;
	std::vector<std::string> ret_vec;

	while (!working_str.empty())
	{
		unsigned int loc = working_str.find(" ");
		// found in string
		if (loc != std::string::npos)
		{
			if (working_str.substr(0, loc) != "")
			{
				ret_vec.push_back(working_str.substr(0, loc));
			}
			working_str = working_str.substr(loc + 1);
		}
		else
		{
			if (working_str != "")
			{
				ret_vec.push_back(working_str);
			}
			break;
		}
	}

	return ret_vec;
}


#endif StringFunctions_CPP