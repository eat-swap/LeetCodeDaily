#include <string>

/**
 * 2437. Number of Valid Clock Times
 *
 * You are given a string of length 5 called time, representing the current time on a digital clock in the format "hh:mm". The earliest possible time is "00:00" and the latest possible time is "23:59".
 * In the string time, the digits represented by the ? symbol are unknown, and must be replaced with a digit from 0 to 9.
 * Return an integer answer, the number of valid clock times that can be created by replacing every ? with a digit from 0 to 9.
 */

class LC230509CN {
public:
	static int countTime(const std::string&) noexcept;
};

bool match(const char* s, const char* t) {
	for (; *s && *t; ++s, ++t)
		if (*s != *t && *t != '?')
			return false;
	return true;
}

int LC230509CN::countTime(const std::string& time) noexcept {
	auto* time_ptr = time.c_str();
	char buf[8];
	int ret = 0;
	for (int h = 0; h < 24; ++h) {
		for (int m = 0; m < 60; ++m) {
			std::sprintf(buf, "%02d:%02d", h, m);
			ret += match(buf, time_ptr);
		}
	}
	return ret;
}

using Solution = LC230509CN;
