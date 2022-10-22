#include <string>
#include <iostream>

/**
 * 76. Minimum Window Substring
 *
 * Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
 * The testcases will be generated such that the answer is unique.
 * A substring is a contiguous sequence of characters within the string.
 */

class Solution {
private:
	static inline int pos_of(char ch) {
		return (ch > 'Z') ? (ch - 'a') : (ch - 'A' + 26);
	}

public:
	static std::string minWindow(const std::string& s, const std::string& t) {
		int m = s.length(), n = t.length();
		const char* sp = s.c_str();
		const char* tp = t.c_str();
		if (m < n)
			return "";

		int seg_tree[128]{};
		for (int i = 0; i < m; ++i)
			++seg_tree[pos_of(sp[i])];
		for (int i = 0; i < n; ++i)
			++seg_tree[64 + pos_of(tp[i])];
		for (int i = 0; i < 52; ++i)
			if (seg_tree[i] < seg_tree[64 + i])
				return "";

		// Initial build of seg tree
		for (int i = 0; i < n; ++i)
			--seg_tree[64 + pos_of(sp[i])];
		for (int i = 64; --i; )
			seg_tree[i] = std::max(seg_tree[i << 1], seg_tree[i << 1 | 1]);
		if (seg_tree[1] <= 0)
			return s.substr(0, n);

		// gradually expand & shrink
		int L = 0, R = n, minL = 0x7FFFFFFF, mL, mR; // L inclusive, R exclusive
		std::string ret;
		while (R < m) {
			// R+
			for (; R < m && seg_tree[1] > 0; ++R) {
				int p = pos_of(sp[R]) + 64;
				--seg_tree[p];
				// Update tree
				while (p >>= 1)
					seg_tree[p] = std::max(seg_tree[p << 1], seg_tree[p << 1 | 1]);
			}

			// L+
			for (; L + n <= R; ++L) {
				int p = pos_of(sp[L]) + 64;
				if (seg_tree[p] >= 0)
					break;
				++seg_tree[p];
			}

			// Update tree after L+ at once
			for (int i = 64; --i; )
				seg_tree[i] = std::max(seg_tree[i << 1], seg_tree[i << 1 | 1]);

			if (seg_tree[1] <= 0 && minL > R - L && R - L > 0)
				minL = (mR = R) - (mL = L);

			// Force update L
			int p = pos_of(sp[L++]) + 64;
			++seg_tree[p];
			while (p >>= 1)
				seg_tree[p] = std::max(seg_tree[p << 1], seg_tree[p << 1 | 1]);
		}
		return s.substr(mL, mR - mL);
	}
};

int main() {
	std::cout << Solution::minWindow("acbdbaab", "aabd") << "\n";
	return 0;
}
