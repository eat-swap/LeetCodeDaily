#include <string>
#include <vector>

/**
 * 面试题 17.11. Find Closest LCCI
 * You have a large text file containing words. Given any two different words, find the shortest distance (in terms of number of words) between them in the file. If the operation will be repeated many times for the same file (but different pairs of words), can you optimize your solution?
 */

class Solution {
public:
	static int findClosest(const std::vector<std::string>& words, const std::string& word1, const std::string& word2) {
		int ans = 0x3FFFFFFF, p1 = 0x3FFFFFFF, p2 = 0x3FFFFFFF, cnt = 0;
		for (const std::string& s : words) {
			if (s == word1) {
				p1 = cnt;
				ans = std::min(std::abs(p2 - p1), ans);
			} else if (s == word2) {
				p2 = cnt;
				ans = std::min(std::abs(p2 - p1), ans);
			}
			++cnt;
		}
		return ans;
	}
};
