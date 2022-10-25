#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

/**
 * 1662. Check If Two String Arrays are Equivalent
 *
 * Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
 * A string is represented by an array if the array elements concatenated in order forms the string.
 */

class Solution {
public:
	static bool arrayStringsAreEqual(const std::vector<std::string>& s, const std::vector<std::string>& t) {
		return std::accumulate(s.begin(), s.end(), std::string()) == std::accumulate(t.begin(), t.end(), std::string());
	}
};