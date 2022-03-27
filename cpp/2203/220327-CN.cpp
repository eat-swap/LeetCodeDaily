#include <vector>
#include <numeric>

/**
 * 2028. Find Missing Observations
 * You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.
 * You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.
 * Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.
 * The average value of a set of k numbers is the sum of the numbers divided by k.
 * Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.
 */

class Solution {
public:
	static std::vector<int> missingRolls(const std::vector<int>& rolls, int mean, int n) {
		int sum = std::accumulate(rolls.begin(), rolls.end(), 0);
		int rem = (n + rolls.size()) * mean - sum;
		if (rem < n || rem > 6 * n)
			return {};
		std::vector<int> ret(n, rem / n);
		rem = rem - rem / n * n;
		for (int& i : ret) {
			if (rem <= 0)
				break;
			if (rem < 6 - i) {
				i += rem;
				break;
			}
			rem -= 6 - i;
			i = 6;
		}
		return ret;
	}
};

int main() {
	auto ret = Solution::missingRolls({1, 5, 6}, 3, 4);
	return 0;
}
