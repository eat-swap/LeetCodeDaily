#include <iostream>
#include <unordered_set>

class Solution {
public:
	static int smallestRepunitDivByK(int k) {
		if (k == 1) return 1;
		/*
		 * Bad code.
		 * Despite std::unordered_set is O(1),
		 * it increases space complexity
		 * and the constant increases.
		int pos = 2, rem = 11 % k;
		std::unordered_set<int> s;
		s.insert(rem);
		while (true) {
			if (!rem)
				return pos;
			rem = (10 * rem + 1) % k;
			++pos;
			if (s.count(rem))
				return -1;
			s.insert(rem);
		}
		 */
		for (int pos = 1, rem = 1; pos < k; ++pos)
			if (!(rem = (10 * rem + 1) % k))
				return ++pos;
		return -1;
	}
};

int main() {
	std::printf("%d\n", Solution::smallestRepunitDivByK(7));
}