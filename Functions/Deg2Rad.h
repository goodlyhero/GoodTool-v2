#pragma once
inline float Deg2Rad(float deg)
{
	constexpr float tmp = 3.141592653589793 / 180;
	return deg * tmp;
}

inline float Rad2Deg(float deg)
{
	constexpr float tmp = 3.141592653589793 / 180;
	return deg / tmp;
}