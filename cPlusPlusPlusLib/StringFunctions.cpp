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
/// <param name="original_str">The original std::string</param>
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
/// Splits the original string into a vector using all delims
/// </summary>
/// <param name="original_str">The original std::string to split.</param>
/// <param name="delims">std::vector<std::string> of delimiters.</param>
/// <returns>std::vector<std::string> of the original_str split by all delims</returns>
std::vector<std::string> StringFunctions::splitIntoVector(const std::string &original_str, const std::vector<std::string> &delims)
{
	std::vector<std::string> working_delims = delims;
	std::vector<std::string> ret_vec;

	if (working_delims.empty())
	{
		return ret_vec;
	}

	ret_vec = StringFunctions::splitIntoVector(original_str, working_delims.front());
	working_delims.erase(working_delims.begin());

	while (!working_delims.empty())
	{
		std::vector<std::string> tmp_vec;
		for (const std::string &cur : ret_vec)
		{
			std::vector<std::string> inner_vec = StringFunctions::splitIntoVector(cur, working_delims.front());

			for (const std::string &cur_in : inner_vec)
			{
				tmp_vec.push_back(cur_in);
			}
		}
		working_delims.erase(working_delims.begin());
		ret_vec = tmp_vec;
	}

	return ret_vec;
}

/// <summary>
/// Splits the original_str into a std::vector by whitespace.
/// </summary>
/// <param name="original_str">The original std::string</param>
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
/// Returns a string where all cases are flipped from original_str
/// </summary>
/// <param name="original_str">The original std::string</param>
/// <returns>original_str with flipped case</returns>
std::string StringFunctions::swapCase(const std::string &original_str)
{
	std::string ret_str = "";

	for (char c : original_str)
	{
		if (islower(c))
		{
			ret_str += toupper(c);
		}
		else
		{
			ret_str += tolower(c);
		}
	}

	return ret_str;
}

/// <summary>
/// Slices the specified original_str between x and y using a python-style slice
/// </summary>
/// <param name="original_str">The original_str.</param>
/// <param name="slice_str">slicing info as string ex: "[1:3]"</param>
/// <returns>std::string slice from original_str. Returns "" on error</returns>
std::string StringFunctions::slice(const std::string &original_str, const std::string &slice_str)
{
	if (slice_str.size() < 3)
	{
		std::cerr << "ERROR: Improper slice string " << slice_str << ". Good Examples: \"[1]\", \"[1:2]\", \"[-1, 5]\", \"[:]\"" << std::endl;
		return "";
	}

	if (slice_str.front() != '[' || slice_str.back() != ']')
	{
		std::cerr << "ERROR: Improper slice string " << slice_str << ". Should start with \"[\" and end with \"]\"" << std::endl;
		return "";
	}

	if (slice_str == "[:]")
	{
		return std::string(original_str);
	}

	std::string working_slice = slice_str;

	//remove []s
	working_slice.erase(0, 1);
	working_slice.erase(working_slice.size() - 1, 1);

	// look for colon
	int colon_loc = working_slice.find(":");


	// colon not found, try to cast to int
	// example [1]
	if (colon_loc == std::string::npos)
	{
		int ret_index = std::stoi(working_slice);
		if ((unsigned int)abs(ret_index) > original_str.size())
		{
			std::cerr << "ERROR: Index " << ret_index << " is out of range" << std::endl;
			return "";
		}
		else if (ret_index < 0)
		{
			ret_index = original_str.size() - abs(ret_index);
		}

		return original_str.substr(ret_index, 1);
	}
	else
	{
		int l_index = 0;
		int r_index = 0;
		try
		{
			l_index = std::stoi(working_slice.substr(0, colon_loc));
		}
		catch (const std::invalid_argument &ia)
		{
			ia.what();

			//something wrong with l_index
			//it might be empty
			if (StringFunctions::isOnlyWhitespace(working_slice.substr(0, colon_loc)))
			{
				l_index = 0;
			}
		}

		try
		{
			r_index = std::stoi(working_slice.substr(colon_loc + 1));
		}
		catch (const std::invalid_argument &ia)
		{
			ia.what();

			//something wrong with r_index
			//it might be empty
			if (StringFunctions::isOnlyWhitespace(working_slice.substr(colon_loc + 1)))
			{
				r_index = original_str.size();
			}
		}

		if (l_index < 0)
		{
			l_index = std::max((int)original_str.size() - abs(l_index), (int)0);
		}

		if (r_index < 0)
		{
			r_index = original_str.size() - abs(r_index);
		}

		if (l_index == r_index || l_index >= r_index || (unsigned int) l_index > original_str.size())
		{
			return "";
		}

		return original_str.substr(l_index, (r_index - l_index));
	}
}

/// <summary>
/// Performs a left and right trim on the specified original_str.
/// </summary>
/// <param name="original_str">The original std::string</param>
/// <param name="removal_chars">Chars to be trimmed (Defaults to all whitespace)</param>
/// <returns>A copy of the original std::string without leading and trailing whitespace</returns>
std::string StringFunctions::trim(const std::string &original_str, const std::string &removal_chars)
{
	std::string working_str = original_str;
	int rtrim_loc = working_str.find_last_not_of(removal_chars) + 1;
	int ltrim_loc = working_str.find_first_not_of(removal_chars);

	if (ltrim_loc == std::string::npos)
	{
		return "";
	}
	else
	{
		return working_str.erase(rtrim_loc).substr(ltrim_loc);
	}
}

/// <summary>
/// Performs a left trim on the specified original_str.
/// </summary>
/// <param name="original_str">The original std::string</param>
/// <param name="removal_chars">Chars to be trimmed (Defaults to all whitespace)</param>
/// <returns>A copy of the original std::string without leading whitespace</returns>
std::string StringFunctions::ltrim(const std::string &original_str, const std::string &removal_chars)
{
	std::string working_str = original_str;
	int ltrim_loc = working_str.find_first_not_of(removal_chars);

	if (ltrim_loc == std::string::npos)
	{
		return "";
	}
	else
	{
		return working_str.substr(ltrim_loc);
	}
}

/// <summary>
/// Performs a right trim on the specified original_str.
/// </summary>
/// <param name="original_str">The original std::string</param>
/// <param name="removal_chars">Chars to be trimmed (Defaults to all whitespace)</param>
/// <returns>A copy of the original std::string without trailing whitespace</returns>
std::string StringFunctions::rtrim(const std::string &original_str, const std::string &removal_chars)
{
	std::string working_str = original_str;
	int rtrim_loc = working_str.find_last_not_of(removal_chars) + 1;

	return working_str.erase(rtrim_loc);
}

/// <summary>
/// Determines if a given std::string only contains whitespace or is empty
/// </summary>
/// <param name="original_str">The original std::string</param>
/// <returns>True if the original_str only contains whitespace</returns>
bool StringFunctions::isOnlyWhitespace(const std::string &original_str)
{
	return original_str.find_first_not_of("\t\n\v\f\r ") == std::string::npos;
}

/// <summary>
/// Determines if the original std::string starts with the check std::string
/// </summary>
/// <param name="original_str">The original std::string.</param>
/// <param name="check">The std::string that will be compared against the start of the original strd::string</param>
/// <param name="case_matters">If true (default), case matters, otherwise all comparisons are done after taking both std::strings toLowerCase()</param>
/// <returns>True if the original std::string starts with the check std::string</returns>
bool StringFunctions::startsWith(const std::string &original_str, const std::string &check, const bool &case_matters)
{
	if (original_str.size() < check.size())
		return false;

	std::string working_str = original_str;
	std::string working_check = check;

	if (!case_matters)
	{
		working_check = StringFunctions::toLowerCase(working_check);
		working_str = StringFunctions::toLowerCase(working_str);
	}

	return (strncmp(working_str.c_str(), working_check.c_str(), working_check.size()) == 0);
}

/// <summary>
/// Determines if the original std::string ends with the check std::string
/// </summary>
/// <param name="original_str">The original std::string.</param>
/// <param name="check">The std::string that will be compared against the end of the original strd::string</param>
/// <param name="case_matters">If true (default), case matters, otherwise all comparisons are done after taking both std::strings toLowerCase()</param>
/// <returns>True if the original std::string ends with the check std::string</returns>
bool StringFunctions::endsWith(const std::string &original_str, const std::string &check, const bool &case_matters)
{
	if (original_str.size() < check.size())
		return false;

	std::string working_str = original_str;
	std::string working_check = check;

	if (!case_matters)
	{
		working_check = StringFunctions::toLowerCase(working_check);
		working_str = StringFunctions::toLowerCase(working_str);
	}

	return (strncmp(working_str.c_str() + (working_str.size() - working_check.size()), working_check.c_str(), working_check.size()) == 0);
}

#endif StringFunctions_CPP