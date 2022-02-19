#include <vector>
#include <iostream>

/**
 * 605. Can Place Flowers
 * You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.
 */

class Solution {
public:
	static bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
		int size = flowerbed.size();
		flowerbed.push_back(0);
		if (!flowerbed[0] && !flowerbed[1]) {
			flowerbed[0] = 1;
			--n;
		}
		for (int i = 1; n && i < size; ++i) {
			if (!flowerbed[i] && !flowerbed[i - 1] && !flowerbed[i + 1]) {
				flowerbed[i] = 1;
				--n;
			}
		}
		return n == 0;
	}
};

int main() {
	std::vector<int> arg {0, 0, 1, 0, 1, 0, 0};
	std::cout << Solution::canPlaceFlowers(arg, 2);
	return 0;
}