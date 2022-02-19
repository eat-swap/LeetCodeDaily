#include <vector>
#include <cstdio>
#include <cstring>

class Solution {
private:
	// Reduce cache miss!
	// inline static int inDegree[1005];
	// inline static int outDegree[1005];
	inline static unsigned degrees[1005][2];
public:
	static int findJudge(int n, const std::vector<std::vector<int>>& trust) {
		int len = trust.size();
		if (len < n - 1) return -1;
		memset(degrees, 0, sizeof degrees);
		// for (const auto& i : trust) {
		for (int i = 0; i < len; ++i) {
			++degrees[trust[i][0]][0];
			++degrees[trust[i][1]][1];
		}
		for (int i = 1; i <= n; ++i) {
			// if (!degrees[i][0] && degrees[i][1] == n - 1)
			if (!(degrees[i][0] | (degrees[i][1] ^ n - 1)))
				return i;
		}
		return -1;
	}
};

int main() {
	std::printf("%d\n", Solution::findJudge(4, {{1, 3},
												{1, 4},
												{2, 3},
												{2, 4},
												{4, 3}}));
	return 0;
}
