#include <string>

/**
 * 680. Valid Palindrome II
 * Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 */

class Solution {
private:
	static bool isPalindrome(const std::string& basicString, int i, int j) {
		for (; i < j; ++i, --j)
			if (basicString[i] != basicString[j])
				return false;
		return true;
	}
public:
	static bool validPalindrome(const std::string& s) {
		for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
			if (s[i] != s[j])
				return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
		return true;
	}
};

