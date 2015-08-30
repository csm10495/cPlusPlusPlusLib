/*
* This is the header file for the UtilityFunctions class of cPlusPlusPlusLib
* cPPPLib - A library of functions that should be in the C++ Standard Library
* (C) - Charles Machalow - MIT License
*/

#ifndef UtilityFunctions_H
#define UtilityFunctions_H

#include <cstdint>
#include <limits>

/// <summary>
/// Class for functions for performing general utilities.
/// </summary>
class UtilityFunctions
{
public:
	static bool isBigEndian();
	static bool isLittleEndian();
};

#endif UtilityFunctions_H