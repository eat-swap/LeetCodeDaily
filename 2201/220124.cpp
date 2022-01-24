#include <cctype>
#include <algorithm>
#include <string>
#include <cstdio>

/**
 * 520. Detect Capital
 * We define the usage of capitals in a word to be right when one of the following cases holds:
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 * Given a string word, return true if the usage of capitals in it is right.
 */

class Solution {
public:
	static bool detectCapitalUse(const std::string& word) {
		// auto n = std::count_if(word.begin(), word.end(), [](int x) { return (bool)std::isupper(x); });
		// Leetcode did not accept direct usage of std::isupper, but MSVC does.
		const auto n = std::count_if(word.begin(), word.end(), std::isupper);
		return (word.length() == n) || (!n) || (n == 1 && std::isupper(*word.begin()));
	}
};

int main() {
	std::printf("%s\n", Solution::detectCapitalUse("USA") ? "true" : "false");
	std::printf("%s\n", Solution::detectCapitalUse("leetcode") ? "true" : "false");
	std::printf("%s\n", Solution::detectCapitalUse("Google") ? "true" : "false");
	std::printf("%s\n", Solution::detectCapitalUse("FlaG") ? "true" : "false");
}
