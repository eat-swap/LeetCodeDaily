#include <vector>
#include <iostream>

/**
 * 1996. The Number of Weak Characters in the Game
 * You are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. You are given a 2D integer array properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.
 *
 * A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.
 *
 * Return the number of weak characters.
 */

class Solution {
public:
	static int numberOfWeakCharacters(std::vector<std::vector<int>>& properties) {
		std::sort(properties.begin(), properties.end(), [](const std::vector<int>& x, const std::vector<int>& y) {
			if (x[0] - y[0])
				return x[0] > y[0];
			return x[1] < y[1];
		});
		int ret = 0, max = -1;
		for (const auto& i : properties)
			if ((max = std::max(i[1], max)) > i[1])
				++ret;
		return ret;
	}
};

int main() {
	std::vector<std::vector<int>> args = {{1,1},{2,1},{2,2},{1,2}};
	std::cout << Solution::numberOfWeakCharacters(args);
	return 0;
}
