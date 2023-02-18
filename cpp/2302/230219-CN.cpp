#include <queue>
#include <utility>
#include <numeric>
#include <execution>

class Solution {
public:
	static double maxAverageRatio(std::vector<std::vector<int>>& c, int ex) {
		int n = c.size();
		double ans = std::transform_reduce(
			std::execution::par,
			c.begin(),
			c.end(),
			0.0,
			std::plus{},
			[](const std::vector<int>& x) {
				return double(x[0]) / double(x[1]);
			}
		);
		std::priority_queue<std::pair<double, int>> incr;
		for (int i = 0; i < n; ++i)
			incr.emplace(double(c[i][0] + 1) / double(c[i][1] + 1) - double(c[i][0]) / double(c[i][1]), i);
		while (ex--) {
			const auto [delta, i] = incr.top();
			incr.pop();
			ans += delta;
			++c[i][0], ++c[i][1];
			incr.emplace(double(c[i][0] + 1) / double(c[i][1] + 1) - double(c[i][0]) / double(c[i][1]), i);
		}
		return ans / n;
	}
};

int main() {
	std::vector<std::vector<int>> c {
		{2,4},{3,9},{4,5},{2,10}
	};
	std::printf("%.6f\n", Solution::maxAverageRatio(c, 4));
	return 0;
}
