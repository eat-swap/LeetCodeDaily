#include <vector>
#include <string>
#include <functional>
#include <iostream>

/**
 * 17. Letter Combinations of a Phone Number
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 */

class Solution {
private:
	const inline static char* key[] {
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz"
	};

public:
	static std::vector<std::string> letterCombinations(const std::string& digits) {
		if (digits.empty())
			return {};

		std::vector<std::string> ret;
		ret.reserve(1 << (digits.length() + 2));
		std::string str;
		str.reserve(8);
		const int n = digits.length();

		std::function<void(int)> dfs = [&](int depth) {
			if (depth >= n) {
				ret.push_back(str);
				return;
			}

			for (const char* ptr = key[digits[depth] - '2']; *ptr; ++ptr) {
				str.push_back(*ptr);
				dfs(depth + 1);
				str.pop_back();
			}
		};

		dfs(0);

		return ret;
	}
};

int main() {
	auto r = Solution::letterCombinations("2");
	for (const auto& i : r) {
		std::cout << i << std::endl;
	}
	return 0;
}
