#include <string>

class Solution {
public:
	static bool isSubsequence(const std::string& t, const std::string& s) {
		int m = s.length(), n = t.length(), i = 0, j = 0;
		while (i < m && j < n) {
			if (s[i++] == t[j])
				++j;
		}
		return j == n;
	}
};

int main() {
	return 0;
}
