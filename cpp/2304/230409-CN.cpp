#include <string>
#include <vector>
#include <iostream>

/**
 * 2399. Check Distances Between Same Letters
 *
 * You are given a 0-indexed string s consisting of only lowercase English letters, where each letter in s appears exactly twice. You are also given a 0-indexed integer array distance of length 26.
 * Each letter in the alphabet is numbered from 0 to 25 (i.e. 'a' -> 0, 'b' -> 1, 'c' -> 2, ... , 'z' -> 25).
 * In a well-spaced string, the number of letters between the two occurrences of the ith letter is distance[i]. If the ith letter does not appear in s, then distance[i] can be ignored.
 * Return true if s is a well-spaced string, otherwise return false.
 */

class Solution {
public:
	static bool checkDistances(const std::string&, const std::vector<int>&);
};

bool Solution::checkDistances(const std::string& s, const std::vector<int>& distance) {
	int pos[26]{};
	std::memset(pos, -1, sizeof pos);
	for (int i = 0; i < s.length(); ++i) {
		int& p = pos[s[i] - 'a'];
		p = i + (p < 0 ? 1 : -p);
	}
	for (int i = 0; i < 26; ++i)
		if (pos[i] >= 0 && pos[i] != distance[i])
			return false;
	return true;
}

int main() {
	std::cout << Solution::checkDistances("abaccb", {
		1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	});
}
