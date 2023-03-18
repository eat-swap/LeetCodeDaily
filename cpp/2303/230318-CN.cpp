#include <string>

/**
 * 1616. Split Two Strings to Make Palindrome
 *
 * You are given two strings a and b of the same length. Choose an index and split both strings at the same index, splitting a into two strings: aprefix and asuffix where a = aprefix + asuffix, and splitting b into two strings: bprefix and bsuffix where b = bprefix + bsuffix. Check if aprefix + bsuffix or bprefix + asuffix forms a palindrome.
 * When you split a string s into sprefix and ssuffix, either ssuffix or sprefix is allowed to be empty. For example, if s = "abc", then "" + "abc", "a" + "bc", "ab" + "c" , and "abc" + "" are valid splits.
 * Return true if it is possible to form a palindrome string, otherwise return false.
 * Notice that x + y denotes the concatenation of strings x and y.
 */

class Solution {
public:
	static bool checkPalindromeFormation(const std::string& a, const std::string& b) {
		const int m = a.length(), n = b.length();
		if (m == 1 || n == 1)
			return true;

		// prefix[shorter](b) + suffix[longer](a)
		// prefix b, base a
		if (n >= ((m >> 1) + (m & 1))) {
			bool OK = true;
			// prefix (i) operates on a first and optionally switches to b
			// suffix (j) always operates on a
			for (int i = (m >> 1) - !(m & 1), j = m >> 1, switched = 0; i >= 0; --i, ++j) {
				if ((switched ? b : a)[i] == a[j])
					continue;
				switched = 1;
				if (b[i] == a[j])
					continue;
				OK = false;
				break;
			}
			if (OK) return true;
		}

		// prefix(a) + suffix(b)
		// prefix a, base b
		if (m >= ((n >> 1) + (n & 1))) {
			bool OK = true;
			for (int i = (n >> 1) - !(n & 1), j = m >> 1, switched = 0; i >= 0; --i, ++j) {
				if ((switched ? a : b)[i] == b[j])
					continue;
				switched = 1;
				if (a[i] == b[j])
					continue;
				OK = false;
				break;
			}
			if (OK) return true;
		}

		// prefix a, base a
		if (n >= m) {
			bool OK = true;
			for (int i = (m >> 1) - !(m & 1), j = m >> 1, switched = 0; i >= 0; --i, ++j) {
				if (((switched |= (j >= m)) ? b : a)[j] == a[i])
					continue;
				switched = 1;
				if (a[i] == b[j])
					continue;
				OK = false;
				break;
			}
			if (OK) return true;
		}

		// prefix b, base b
		if (m >= n) {
			bool OK = true;
			for (int i = (n >> 1) - !(n & 1), j = m >> 1, switched = 0; i >= 0; --i, ++j) {
				if (((switched |= (j >= n)) ? a : b)[j] == b[i])
					continue;
				switched = 1;
				if (b[i] == a[j])
					continue;
				OK = false;
				break;
			}
			if (OK) return true;
		}

		// can NEVER reach here
		return false;
	}
};

int main() {
	bool ans = Solution::checkPalindromeFormation(
		"aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd",
		"uvebspqckawkhbrtlqwblfwzfptanhiglaabjea"
	);
	std::printf(ans ? "true" : "false");
	return 0;
}
