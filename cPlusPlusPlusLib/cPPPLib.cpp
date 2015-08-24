/*
* This is the main cpp file for cPlusPlusPlusLib
* cPPPLib - A library of functions that should be in the C++ Standard Library
* (C) - Charles Machalow - MIT License
*/

#ifndef cPPPLib_CPP
#define cPPPLib_CPP

#include "cPPPLib.h"

/// <summary>
/// Splits the original_str into a std::vector by delimiter
/// </summary>
/// <param name="original_str">The original_str.</param>
/// <param name="delim">The delimiter.</param>
/// <returns></returns>
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
/// <returns></returns>
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

int main()
{
	std::cout << "cPlusPlusPlusLib Version " << cPPPLib_H::cPPPLib_V << std::endl << "(C) - Charles Machalow - MIT License" << std::endl;
	
	std::string t = "a";
	std::vector<std::string> tmp = StringFunctions::splitIntoVectorByWhitespace("     ");

	system("PAUSE");
	return 1;
}

#endif cPPPLib_CPP