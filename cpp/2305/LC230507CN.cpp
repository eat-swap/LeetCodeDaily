#include <vector>

/**
 * 1010. Pairs of Songs With Total Durations Divisible by 60
 *
 * You are given a list of songs where the ith song has a duration of time[i] seconds.
 * Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.
 */

class LC230507CN {
public:
	static int numPairsDivisibleBy60(const std::vector<int>&) noexcept;
};

int LC230507CN::numPairsDivisibleBy60(const std::vector<int>& time) noexcept {
	int cnt[60]{}, ret = 0;
	for (int i : time) {
		ret += cnt[(60 - i % 60) % 60];
		++cnt[i % 60];
	}
	return ret;
}
