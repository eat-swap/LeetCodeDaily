#include <string>
#include <vector>
#include <iostream>

inline constexpr int sgn(int x) { return x ? (x > 0 ? 1 : -1) : 0; }

/**
 * 165. Compare Version Numbers
 * Given two version numbers, version1 and version2, compare them.
 *
 * Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.
 *
 * To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.
 *
 * Return the following:
 *
 * If version1 < version2, return -1.
 * If version1 > version2, return 1.
 * Otherwise, return 0.
 */

class Version {
private:
	std::vector<int> revisions;
public:
	explicit Version(std::vector<int> v = {1}) : revisions(std::move(v)) {}

	explicit Version(const std::string& str) {
		int pos = -1;
		revisions.clear();
		const char* s = str.c_str();

		do {
			int x = std::atoi(s + pos + 1);
			revisions.push_back(x);
		} while (-1 != (pos = str.find('.', pos + 1)));
	}

	int compareTo(const Version& rhs) const {
		int m = this->revisions.size(), n = rhs.revisions.size();
		int k = std::max(m, n);
		for (int i = 0; i < k; ++i)
			if (sgn((i < m ? this->revisions[i] : 0) - (i < n ? rhs.revisions[i] : 0)))
				return sgn((i < m ? this->revisions[i] : 0) - (i < n ? rhs.revisions[i] : 0));
		return 0;
	}
};

class Solution {
public:
	static int compareVersion(const std::string& version1, const std::string& version2) {
		return Version(version1).compareTo(Version(version2));
	}
};

int main() {
	std::cout << Solution::compareVersion("1.01", "1.001");
	std::cout << Solution::compareVersion("1.0", "1.0.0");
	std::cout << Solution::compareVersion("0.1", "1.1");
	return 0;
}
