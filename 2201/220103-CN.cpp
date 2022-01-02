#include <iostream>
#include <string>

/**
 * #1185. Day of the Week
 * Given a date, return the corresponding day of the week for that date.
 * The input is given as three integers representing the day, month and year respectively.
 * Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.
 *
 * Input: day = 18, month = 7, year = 1999
 * Output: "Sunday"
 *
 * Range: year <- [1971, 2100]
 */

class Solution {
private:
	inline static const std::string weekName[7] = {
			"Sunday",
			"Monday",
			"Tuesday",
			"Wednesday",
			"Thursday",
			"Friday",
			"Saturday"
	};
	inline static const int monthDays[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
public:
	static std::string dayOfTheWeek(int day, int month, int year) {
		// Starts at 1969-01-01 [Wednesday]
		// (365 * 4 + 1) % 7 == 5, 365 % 7 == 1
		// 1969, +1 ~ +3 will not experience leap years.
		return weekName[(3 + (((year - 1969) >> 2) * 5) + ((year - 1969) & 3) + monthDays[month - 1] + day - 1 + (((year - 1969) & 3) == 3 && month > 2 && year != 2100 ? 1 : 0)) % 7];
	}
};

int main() {
	int n[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int ans, prev = 4;
	for (int y = 1971; y <= 2100; ++y) {
		for (int m = 1; m <= 12; ++m) {
			for (int d = 1; d <= ((!(y & 3) && m == 2 && y != 2100) ? 29 : n[m - 1]); ++d) {
				if ((ans = /* Solution::dayOfTheWeek(d, m, y) int when debug */ 0) != (prev = (prev + 1) % 7)) {
					std::printf("%d-%02d-%02d -> %d != %d\n", y, m, d, ans, prev);
					std::printf("ILLEGAL!\n");
					return 1;
				}
			}
		}
	}
	return 0;
}
