/*
* This is the header file for the UtilityFunctions class of cPlusPlusPlusLib
* cPPPLib - A library of functions that should be in the C++ Standard Library
* (C) - Charles Machalow - MIT License
*/

#ifndef UtilityFunctions_H
#define UtilityFunctions_H

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#ifdef _WIN32
#define NOMINMAX
#include "windows.h"
#endif //_WIN32

#ifdef __linux
#include <sys/vfs.h>
#endif //__linux

/// <summary>
/// Class for functions for performing general utilities.
/// </summary>
class UtilityFunctions
{
public:
	static bool isBigEndian();
	static bool isLittleEndian();
	static bool getFreeSpaceInBytes(uint64_t &space, const std::string &path);

	static void cperror(const char *text, const bool &use_perror=true);

	static std::vector<uint8_t>numericToLEBytes(const uint64_t &numeric);
	static std::vector<uint8_t>numericToBEBytes(const uint64_t &numeric);
};

#endif UtilityFunctions_H