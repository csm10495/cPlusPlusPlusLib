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

/// <summary>
/// Gets the free space in bytes accessable at the given path.
/// Windows: Uses GetDiskFreeSpaceExA() to get free space information
/// Linux: Uses statfs() to get free space information
/// </summary>
/// <param name="space">A uint64_t, passed by reference. On success, will get the available space in bytes</param>
/// <param name="path">A path to use to check for available space</param>
/// <returns>True on success, On failure will do a perror(...) call then return false</returns>
bool UtilityFunctions::getFreeSpaceInBytes(uint64_t &space, const std::string &path)
{
#ifdef _WIN32
	std::string loc = "";

	// Assume a drive letter only was given
	if (path.size() == 1)
	{
		loc = path + ":\\";
	}
	else
	{
		loc = path;
	}

	if (!GetDiskFreeSpaceExA(loc.c_str(), NULL, NULL, (PULARGE_INTEGER)&space))
	{
		UtilityFunctions::cperror("GetDiskFreeSpaceExA() failed", false);
		return false;
	}

	return true;
#endif //_WIN32
#ifdef __linux
	struct statfs buf;

	if (statfs(path.c_str(), &buf) != 0)
	{
		perror("statfs() failed");
		return false;
	}
	space = static_cast<uint64_t>(buf.f_bsize) * static_cast<uint64_t>(buf.f_blocks);

	return true;
#endif //__linux
}

/// <summary>
/// Provide linux-esque perror-esque functionality
/// Windows: GetLastError(), FormatMessageA() or perror() are used to get error text
/// Linux: Just calls perror(text)
/// </summary>
/// <param name="text">The text placed at the start of the error printing</param>
/// <param name="use_perror">Does nothing on Linux. If True, use perror instead of GetLastError() on Windows</param>
void UtilityFunctions::cperror(const char * text, const bool &use_perror)
{
#ifdef _WIN32
	if (use_perror)
	{
		perror(text);
	}
	else
	{
		LPSTR message_buf = nullptr;

		// The FORMAT_MESSAGE_ALLOCATE_BUFFER flag uses LocalAlloc to make the message_buf
		// Which is why there is a LocalFree later to free the dynamic allocation
		size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&message_buf, 0, NULL);

		std::string message(message_buf, size);

		LocalFree(message_buf);

		std::cerr << text << ": " << message;
	}
#endif //_WIN32
#ifdef __linux
	perror(text);
#endif //__linux
}

/// <summary>
/// Numerics of max 64 bits to a std::vector<uint8_t> of bytes
/// </summary>
/// <param name="numeric">The numeric as a uint64_t</param>
/// <returns>std::vector<uint8_t> of bytes in Little Endian form</returns>
std::vector<uint8_t> UtilityFunctions::numericToLEBytes(const uint64_t &numeric)
{
	uint64_t myNumeric = numeric;
	unsigned int numBytes = 0;

	if (numeric <= 0xFF)
	{
		numBytes = sizeof(uint8_t);
	}
	else if (numeric > 0xFF && numeric <= 0xFFFF)
	{
		numBytes = sizeof(uint16_t);
	}
	else if (numeric > 0xFFFF && numeric <= 0xFFFFFFFF)
	{
		numBytes = sizeof(uint32_t);
	}
	else
	{
		numBytes = sizeof(uint64_t);
	}
	std::vector<unsigned char> bytes;

	for (unsigned int i = 0; i < numBytes; i++)
	{
		bytes.push_back(myNumeric & 0xFF);
		myNumeric = myNumeric >> 8;
	}

	return bytes;
}

/// <summary>
/// Numerics of max 64 bits to a std::vector<uint8_t> of bytes
/// </summary>
/// <param name="numeric">The numeric as a uint64_t</param>
/// <returns>std::vector<uint8_t> of bytes in Big Endian form</returns>
std::vector<uint8_t> UtilityFunctions::numericToBEBytes(const uint64_t &numeric)
{
	std::vector<uint8_t> bytes = numericToLEBytes(numeric);
	std::reverse(bytes.begin(), bytes.end());
	return bytes;
}

#endif UtilityFunctions_CPP