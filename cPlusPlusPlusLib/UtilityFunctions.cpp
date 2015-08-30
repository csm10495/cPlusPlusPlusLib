/*
* This is the cpp file for the UtilityFunctions class of cPlusPlusPlusLib
* cPPPLib - A library of functions that should be in the C++ Standard Library
* (C) - Charles Machalow - MIT License
*/

#ifndef UtilityFunctions_CPP
#define UtilityFunctions_CPP

#include "UtilityFunctions.h"

/// <summary>
/// Determines whether this computer uses big endian ordering
/// </summary>
/// <returns>True if the computer uses big endian ordering</returns>
bool UtilityFunctions::isBigEndian()
{
	volatile union {
		uint16_t i;
		unsigned char c[sizeof(uint16_t)];
	} u = { static_cast<uint16_t>(std::numeric_limits<uint16_t>::max() - std::numeric_limits<uint8_t>::max()) };

	return u.c[0] != 0;
}

/// <summary>
/// Determines whether this computer uses little endian ordering
/// </summary>
/// <returns>True if the computer uses little endian ordering</returns>
bool UtilityFunctions::isLittleEndian()
{
	volatile union {
		uint16_t i;
		unsigned char c[sizeof(uint16_t)];
	} u = { static_cast<uint16_t>(std::numeric_limits<uint16_t>::max() - std::numeric_limits<uint8_t>::max()) };

	return u.c[0] == 0;
}

#endif UtilityFunctions_CPP