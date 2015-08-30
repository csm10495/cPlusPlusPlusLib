/*
* This is the header file for the VectorFunctions class of cPlusPlusPlusLib
* cPPPLib - A library of functions that should be in the C++ Standard Library
* (C) - Charles Machalow - MIT License
*/

#ifndef VectorFunctions_H
#define VectorFunctions_H

#include <algorithm>
#include <limits>
#include <vector>

/// <summary>
/// Class of functions for std::vectors.
/// </summary>
class VectorFunctions
{
public:
	/// <summary>
	/// Zips the two given std::vectors into a std::vector<std::pair<T1, T2>>
	/// Starts from the start of the std::vectors
	/// </summary>
	/// <param name="vec1">Given std::vector 1</param>
	/// <param name="vec2">Given std::vector 2</param>
	/// <returns>The zipped std::vector of std::pair<T1,T2></returns>
	template <typename T1, typename T2> static std::vector<std::pair<T1, T2>> zip(const std::vector<T1> &vec1, const std::vector<T2> &vec2)
	{
		size_t smaller_size = std::min(vec1.size(), vec2.size());

		std::vector<std::pair<T1, T2>> ret_vec;

		if (smaller_size == 0 || larger_size == 0)
		{
			return ret_vec;
		}

		for (size_t i = 0; i < smaller_size; i++)
		{
			ret_vec.push_back(std::make_pair(vec1[i], vec2[i]));
		}

		return ret_vec;
	}

	/// <summary>
	/// Zips the two given std::vectors into a std::vector<std::pair<T1, T2>>
	/// Starts from the back of the std::vectors
	/// </summary>
	/// <param name="vec1">Given std::vector 1</param>
	/// <param name="vec2">Given std::vector 2</param>
	/// <returns>The zipped std::vector of std::pair<T1,T2></returns>
	template <typename T1, typename T2> static std::vector<std::pair<T1, T2>> zipb(const std::vector<T1> &vec1, const std::vector<T2> &vec2)
	{
		size_t smaller_size = std::min(vec1.size(), vec2.size());
		size_t larger_size = std::max(vec1.size(), vec2.size());

		std::vector<std::pair<T1, T2>> ret_vec;

		if (smaller_size == 0 || larger_size == 0)
		{
			return ret_vec;
		}

		size_t j = larger_size - 1;
		for (size_t i = smaller_size - 1; i != std::numeric_limits<size_t>::max(); i--)
		{
			ret_vec.push_back(std::make_pair(vec1[i], vec2[j]));
			j--;
		}

		return ret_vec;
	}

	/// <summary>
	/// Flattens the (2 leveled) original std::vector
	/// </summary>
	/// <param name="original_vec">The original std::vector<std::vector<T>></param>
	/// <returns>A flattened std::vector<T></returns>
	template <typename T> static std::vector<T> flatten(const std::vector<std::vector<T>> &original_vec)
	{
		std::vector<T> ret_vec;

		for (const std::vector<T> &outer_item : original_vec)
		{
			for (const T &inner_item : outer_item)
			{
				ret_vec.push_back(inner_item);
			}
		}

		return ret_vec;
	}
};

#endif VectorFunctions_H