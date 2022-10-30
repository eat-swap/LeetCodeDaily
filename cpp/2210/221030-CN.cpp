#include <vector>
#include <functional>
#include <cctype>

/**
 * 784. Letter Case Permutation
 *
 * Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
 * Return a list of all possible strings we could create. Return the output in any order.
 */

class Solution {
public:
	std::vector<std::string> letterCasePermutation(std::string& s) {
		std::vector<std::string> ret;
		std::function<void(int)> f = [&](int pos) {
			if (pos >= s.length()) {
				ret.push_back(s);
			} else if (std::isalpha(s[pos])) {
				s[pos] = std::tolower(s[pos]);
				f(1 + pos);
				s[pos] = std::toupper(s[pos]);
				f(1 + pos);
			} else {
				f(1 + pos);
			}
		};
		f(0);
		return ret;
	}
};
