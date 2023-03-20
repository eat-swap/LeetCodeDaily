#include <vector>

/**
 * 605. Can Place Flowers
 * You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.
 *
 * Refer: 220118.cpp
 */

class Solution {
public:
	static bool canPlaceFlowers(const std::vector<int>& flowerbed, int n) {
		int cont0 = 1;
		for (int i : flowerbed) {
			if (i) {
				n -= (cont0 - 1) / 2;
				cont0 = 0;
			} else ++cont0;
		}
		return (n - cont0 / 2) <= 0;
	}
};
