/*
 * Utilities.cpp
 *
 *  Created on: Nov 11, 2013
 *      Author: brydev
 */

#include "Utilities.h"

namespace Utils {
	std::string Utilities::convertInt(int number)
	{
		std::stringstream ss;
		ss << number;
		return ss.str();
	}
} /* namespace Utils */
