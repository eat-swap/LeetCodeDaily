#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 * 318. Maximum Product of Word Lengths
 * Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.
 */

class Solution {
public:
	static int maxProduct(const std::vector<std::string>& words) {
		const int n = words.size();
		std::vector<std::pair<uint16_t, uint32_t>> w;
		w.reserve(n);
		for (const std::string& s : words) {
			uint32_t set = 0;
			for (const char c : s)
				set |= 1 << (c - 'a');
			w.emplace_back(s.length(), set);
		}
		int ret = 0;
		for (int i = 0; i < n; ++i) {
			const auto& [l1, s1] = w[i];
			for (int j = i + 1; j < n; ++j) {
				const auto& [l2, s2] = w[j];
				if (!(s1 & s2))
					ret = std::max(ret, l1 * l2);
			}
		}
		return ret;
	}
};

int main() {
	std::cout << Solution::maxProduct({"abcw","baz","foo","bar","xtfn","abcdef"});
	return 0;
}
