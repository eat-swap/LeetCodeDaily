#include <vector>
#include <string>

/**
 * 944. Delete Columns to Make Sorted
 * You are given an array of n strings strs, all of the same length.
 * You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted while column 1 ('b', 'c', 'a') is not, so you would delete column 1.
 * Return the number of columns that you will delete.
 */

class Solution {
public:
	static int minDeletionSize(const std::vector<std::string>& s) {
		auto n = s.front().length(), m = s.size();
		int cnt = 0;
		while (n--) {
			bool ok = true;
			for (int i = m - 1; i--; ) {
				if (s[i][n] > s[1 + i][n]) {
					ok = false;
					break;
				}
			}
			cnt += !ok;
		}
		return cnt;
	}
};
