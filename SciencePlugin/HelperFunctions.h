#pragma once

#include <string>
#include <iomanip>
#include <sstream>

#include "bakkesmod\plugin\bakkesmodplugin.h"

namespace sp
{
	template <typename T>
	std::string to_string_decimals(const T a_value, int n)
	{
		std::ostringstream out;
		out << std::fixed << std::setprecision(n) << a_value;
		return out.str();
	}

	template <typename T>
	std::string to_string_decimals_scientific(const T a_value, int n, int treshold)
	{
		std::ostringstream out;
		if (abs(a_value) > (float)pow(10, -treshold)) // for big enough values, just use normal notation
			out << std::fixed << std::setprecision(n) << a_value;
		else
			out << std::fixed << std::setprecision(n-treshold) << std::scientific << a_value;
		return out.str();
	}

	std::string vector_to_string(Vector v, int prec = 2);
	std::string rot_to_string(Rotator v, int prec = 8);
	std::string quat_to_string(FQuat v, int prec = 10);

	std::string to_string(float f, int prec = 2);
	std::string to_string_scientific(float f, int prec = 11, int treshold = 4);

	bool vector_eq(Vector v1, Vector v2);
	bool quat_eq(FQuat q1, FQuat q2);
	bool rot_eq(Rotator r1, Rotator r2);

	Vector quatToFwd(FQuat quat);
	Vector quatToRight(FQuat quat);
	Vector quatToUp(FQuat quat);

	Vector rotateVectorWithQuat(Vector v, FQuat q);

}