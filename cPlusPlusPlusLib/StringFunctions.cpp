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

/// <summary>
/// Returns a copy of the given string in Title Case
/// </summary>
/// <param name="original_str">The original std::string</param>
/// <returns>Copy of original_str in Title Case</returns>
std::string StringFunctions::toTitleCase(const std::string &original_str)
{
	char last_char = ' ';
	std::string ret_str = "";

	for (char c : original_str)
	{
		if (last_char == ' ')
		{
			ret_str += toupper(c);
		}
		else
		{
			ret_str += c;
		}
		last_char = c;
	}

	return ret_str;
}

/// <summary>
/// Returns a copy of the given string in UPPERCASE
/// </summary>
/// <param name="original_str">The original std::string</param>
/// <returns>Copy of original_str in UPPERCASE</returns>
std::string StringFunctions::toUpperCase(const std::string &original_str)
{
	std::string ret_str = "";

	for (char c : original_str)
	{
		ret_str += toupper(c);
	}

	return ret_str;
}

/// <summary>
/// Returns a copy of the given string in lowercase
/// </summary>
/// <param name="original_str">The original std::string</param>
/// <returns>Copy of original_str in lowercase</returns>
std::string StringFunctions::toLowerCase(const std::string &original_str)
{
	std::string ret_str = "";

	for (char c : original_str)
	{
		ret_str += tolower(c);
	}

	return ret_str;
}

/// <summary>
/// Determines if a given std::string only contains whitespace or is empty
/// </summary>
/// <param name="original_str">The original_str.</param>
/// <returns>True if the original_str only contains whitespace</returns>
bool StringFunctions::isOnlyWhitespace(const std::string & original_str)
{
	return original_str.find_first_not_of("\t\n\v\f\r") == std::string::npos;
}

#endif StringFunctions_CPP