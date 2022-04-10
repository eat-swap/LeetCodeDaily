#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <queue>

/**
 * 347. Top K Frequent Elements
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 *
 * Complexity analysis:
 * Solution: O(n + k)
 * Solution2: O(n + n * log(k))
 * Solution3: O(n + k * log(n))
 *
 * But "Solution" is the slowest.
 */

class Solution {
public:
	static std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
		auto* cnt = new std::unordered_set<int>[100000 + 1];
		std::unordered_map<int, int> m;
		int max_cnt = 1;
		for (int x : nums) {
			if (!m.count(x)) {
				m[x] = 1;
				cnt[1].insert(x);
			} else {
				cnt[m[x]].erase(x);
				cnt[++m[x]].insert(x);
				max_cnt = std::max(max_cnt, m[x]);
			}
		}
		std::vector<int> ret;
		for (int i = max_cnt; i > 0 && k > 0; --i) {
			if (cnt[i].size() <= k) {
				k -= cnt[i].size();
				ret.insert(ret.end(), cnt[i].cbegin(), cnt[i].cend());
			} else {
				ret.insert(ret.end(), cnt[i].begin(), std::next(cnt[i].begin(), k));
			}
		}
		delete[] cnt;
		return ret;
	}
};

class Solution2 {
public:
	static std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
		std::unordered_map<int, int> m;
		for (int x : nums)
			++m[x];
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
		for (const auto& [idx, cnt] : m) {
			q.push({cnt, idx});
			if (q.size() > k)
				q.pop();
		}
		while (q.size() > k)
			q.pop();
		std::vector<int> ret;
		ret.reserve(k);
		while (!q.empty()) {
			ret.push_back(q.top().second);
			q.pop();
		}
		return ret;
	}
};

struct PairSecondCmp {
	bool operator()(const std::pair<int, int> x, const std::pair<int, int> y) {
		return x.second < y.second;
	}
};

class Solution3 {
public:
	static std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
		std::unordered_map<int, int> m;
		for (int x : nums)
			++m[x];
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairSecondCmp> q(m.begin(), m.end());
		std::vector<int> ret;
		ret.reserve(k);
		for (int i = 0; i < k; ++i) {
			ret.push_back(q.top().second);
			q.pop();
		}
		return ret;
	}
};

int main() {
	auto ret = Solution3::topKFrequent({5,2,5,3,5,3,1,1,3}, 2);
	return 0;
}
