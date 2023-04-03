#include <algorithm>
#include <iostream>
#include <vector>

/**
 * 881. Boats to Save People
 *
 * You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
 * Return the minimum number of boats to carry every given person.
 */

class Solution {
public:
	static int numRescueBoats(const std::vector<int>& people, int limit) {
		std::vector<uint16_t> bucket(30005);
		for (int i : people)
			++bucket[i];
        int ans = bucket[limit], i = 1, j = limit - 1, delta;
        for (; i < j; --j) {
            if (!bucket[j])
                continue;
            while (bucket[j] && i + j <= limit && i < j) {
                delta = std::min(bucket[j], bucket[i]);
                bucket[j] -= delta;
                bucket[i] -= delta;
                ans += delta;
                if (!bucket[i])
                    ++i;
            }
            if (bucket[j]) {
				if (i == j && i + j <= limit)
					ans += (bucket[i] >> 1) + (bucket[i] & 1);
				else
					ans += bucket[j];
			}
            bucket[j] = 0;
        }
        if (bucket[i])
            ans += (bucket[i] >> 1) + (bucket[i] & 1);
        return ans;
	}
};

int main() {
    std::cout << Solution::numRescueBoats({2,2}, 6);
    return 0;
}
