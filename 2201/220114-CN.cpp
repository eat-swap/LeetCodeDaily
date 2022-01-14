#include <vector>
#include <iostream>
#include <queue>

class Solution {
private:
	static auto getCartesianProduct(const std::vector<int>& p, const std::vector<int>& q, int limP, int limQ) {
		std::vector<std::vector<int>> ret;
		for (int i = 0; i < limP; ++i) {
			for (int j = 0; j < limQ; ++j) {
				ret.push_back({p[i], q[j]});
			}
		}
		return ret;
	}
public:
	static auto kSmallestPairs(const std::vector<int>& nums1, const std::vector<int>& nums2, int k) {
		auto n1 = nums1.size(), n2 = nums2.size();
		if (k >= n1 * n2)
			return getCartesianProduct(nums1, nums2, n1, n2);
		std::vector<std::vector<int>> ret;

		auto cmp = [&] (const std::vector<int>& i, const std::vector<int>& j) {
			return nums1[i[0]] + nums2[i[1]] > nums1[j[0]] + nums2[j[1]];
		};

		std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp)> q(cmp);
		for (int i = 0; i < n1; ++i) {
			q.push({i, 0});
		}

		for (int i = 0; i < k; ++i) {
			auto t = q.top();
			q.pop();
			ret.push_back({nums1[t[0]], nums2[t[1]]});
			if (1 + t[1] < n2)
				q.push({t[0], 1 + t[1]});
		}

		return ret;
	}
};

int main() {
	auto ret = Solution::kSmallestPairs({-10, -4, 0, 0, 6}, {3, 5, 6, 7, 8, 100}, 10);
	for (const auto& i: ret) {
		std::printf("[%d, %d]\n", i[0], i[1]);
	}
	return 0;
}
