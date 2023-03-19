#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>

/**
 * 1625. Lexicographically Smallest String After Applying Operations
 *
 * You are given a string s of even length consisting of digits from 0 to 9, and two integers a and b.
 *
 * You can apply either of the following two operations any number of times and in any order on s:
 *
 * Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back to 0. For example, if s = "3456" and a = 5, s becomes "3951".
 * Rotate s to the right by b positions. For example, if s = "3456" and b = 1, s becomes "6345".
 * Return the lexicographically smallest string you can obtain by applying the above operations any number of times on s.
 *
 * A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "0158" is lexicographically smaller than "0190" because the first position they differ is at the third letter, and '5' comes before '9'.
 */

class Solution {
private:
	static inline std::string rotate(const std::string& s, int b) {
		return b == s.length() ? s : (s.substr(s.length() - b) + s.substr(0, s.length() - b));
	}

	static inline std::string plus(std::string s, int a) {
		for (int i = 1; i < s.length(); i += 2)
			s[i] = '0' + (s[i] - '0' + a) % 10;
		return s;
	}

public:
	static std::string findLexSmallestString(std::string s, int a, int b) {
		std::queue<std::string> q;
		std::unordered_set<std::string> set;
		q.push(s);
		set.insert(s);
		while (!q.empty()) {
			std::string str = q.front();
			q.pop();
			std::string rot = rotate(str, b);
			if (!set.count(rot)) {
				set.insert(rot);
				q.push(std::move(rot));
			}
			std::string add = plus(str, a);
			if (!set.count(add)) {
				set.insert(add);
				q.push(std::move(add));
			}
			if (str < s)
				s = std::move(str);
		}
		return s;
	}
};

int main() {
	std::cout << Solution::findLexSmallestString("5525", 9, 2);
}
