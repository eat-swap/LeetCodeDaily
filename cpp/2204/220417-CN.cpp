#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <unordered_map>

/**
 * 819. Most Common Word
 * Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.
 * The words in paragraph are case-insensitive and the answer should be returned in lowercase.
 */

class Solution {
public:
	static std::string mostCommonWord(std::string paragraph, const std::vector<std::string>& banned) {
		std::unordered_map<std::string, int> freq;
		std::for_each(paragraph.begin(), paragraph.end(), [](char& c){ c = std::tolower(c); });
		paragraph.push_back('.');
		const char* ptr = paragraph.c_str();
		for (const char* p1 = ptr, * p2 = ptr; *p2; ++p2) {
			if (!std::isalpha(*p2)) {
				if (p2 - p1)
					++freq[std::string(p1, p2)];
				p1 = 1 + p2;
			}
		}
		std::for_each(banned.cbegin(), banned.cend(), [&freq](const std::string& str) { freq.erase(str); });
		return std::max_element(freq.cbegin(), freq.cend(), [](const std::pair<std::string, int>& x, const std::pair<std::string, int>& y) { return x.second < y.second; })->first;
	}
};

int main() {
	std::cout << Solution::mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", {"hit"});
}
