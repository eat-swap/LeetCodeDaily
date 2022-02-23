#include <vector>
#include <iostream>

class Solution {
public:
	static std::vector<int> findBall(const std::vector<std::vector<int>>& grid) {
		const int n = grid.front().size();
		std::vector<int> ret(n);
		for (int i = 0; i < n; ++i) {
			ret[i] = i;
		}

		for (auto it = grid.begin(); it != grid.end(); ++it) {
			const std::vector<int>& now = *it;
			for (int i = 0; i < n; ++i) {
				if (ret[i] == -1)
					continue;
				if (ret[i] < n - 1 && now[ret[i]] == 1 && now[ret[i] + 1] == 1) { // goes R
					++ret[i];
				} else if (ret[i] && now[ret[i]] == -1 && now[ret[i] - 1] == -1) { // goes L
					--ret[i];
				} else { // nowhere to go!
					ret[i] = -1;
				}
			}
		}

		return ret;
	}
};

int main() {
	// auto ret = Solution::findBall({{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}});
	// auto ret = Solution::findBall({{-1}});
	auto ret = Solution::findBall({{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1}});
	for (auto i : ret) {
		std::cout << i << ' ';
	}
}
