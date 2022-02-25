#include <string>
#include <vector>
#include <iostream>

inline constexpr int sgn(int x) { return x ? (x > 0 ? 1 : -1) : 0; }

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
