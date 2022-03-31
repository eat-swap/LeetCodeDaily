#include <vector>
#include <map>
#include <iostream>

/**
 * 954. Array of Doubled Pairs
 * Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.
 */

class Solution {
public:
	static bool canReorderDoubled(const std::vector<int>& arr) {
		std::map<int, int> s[2];
		for (int i : arr)
			++s[i >= 0][std::abs(i)];
		for (std::map<int, int>& m : s) {
			while (!m.empty()) {
				int n = m.begin()->first;
				if (!--m[n])
					m.erase(n);
				if (!m.count(2 * n))
					return false;
				if (!--m[2 * n])
					m.erase(2 * n);
			}
		}
		return true;
	}
};

int main() {
	std::cout << Solution::canReorderDoubled({2,4,0,0,8,1});
	return 0;
}
