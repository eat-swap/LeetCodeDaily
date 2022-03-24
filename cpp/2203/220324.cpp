#include <vector>
#include <algorithm>

/**
 * 881. Boats to Save People
 * You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
 * Return the minimum number of boats to carry every given person.
 */

class Solution {
public:
	static int numRescueBoats(const std::vector<int>& people, int limit) {
		int cnt[30005]{};
		for (int i : people)
			++cnt[i];
		int L = 0, R = 30004, ret = 0;
		for (; L <= R; ++ret) {
			while (!cnt[L] && L <= R)
				++L;
			while (!cnt[R] && L <= R)
				--R;
			if (!cnt[R])
				break;
			--cnt[R];
			if (cnt[L] && L + R <= limit)
				--cnt[L];
		}
		return ret;
	}
};

class SolutionOld {
public:
	static int numRescueBoats(std::vector<int>& people, int limit) {
		std::sort(people.begin(), people.end());
		int ret = 0, L = 0, R = people.size() - 1;
		for (; L <= R; ++ret, --R) {
			if (people[R] + people[L] <= limit)
				++L;
		}
		return ret;
	}
};
