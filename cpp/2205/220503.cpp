#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

/**
 * 581. Shortest Unsorted Continuous Subarray
 * Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.
 * Return the shortest such subarray and output its length.
 */

class Solution {
public:
	static int findUnsortedSubarray(const std::vector<int>& n) {
		int x = n.size(), f = 0, r = x - 1;
		int maxF = n[f], minF = n[f], maxR = n[r], minR = n[r];
		while (f + 1 < x && n[f] <= n[f + 1]) {
			++f;
			maxF = std::max(n[f], maxF);
			minF = std::min(n[f], minF);
		}
		while (r - 1 > 0 && n[r - 1] < n[r]) {
			--r;
			maxR = std::max(n[r], maxR);
			minR = std::min(n[r], minR);
		}

		// todo: SegTree
		// Use segment tree to implement makes it O(n).
	}
};

class SolutionOld {
public:
	static int findUnsortedSubarray(const std::vector<int>& n) {
		if (std::is_sorted(n.begin(), n.end()))
			return 0;

		std::multiset<int> s(n.begin(), n.end());

		int f = 0, r = n.size() - 1;
		while (f < r) {
			bool m = false;
			if (n[f] == *s.begin()) {
				s.erase(s.begin());
				++f;
				m = true;
			}
			auto last = std::prev(s.end());
			if (n[r] == *last) {
				s.erase(last);
				--r;
				m = true;
			}
			if (!m)
				break;
		}
		return r - f + 1;
	}
};

int main() {
	std::cout << Solution::findUnsortedSubarray({1,3,2,3,3});
	return 0;
}
