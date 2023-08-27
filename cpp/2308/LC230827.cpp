#include <functional>
#include <unordered_map>
#include <vector>

class LC230827 {
public:
	static bool canCross(const std::vector<int>&);
};

bool LC230827::canCross(const std::vector<int>& stones) {
	if (stones[1] != 1)
		return false;

	const int n = stones.size();
	std::unordered_map<unsigned long long, int> can_jump;
	std::unordered_map<int, int> rev;
	for (int i = 0; i < n; ++i)
		rev[stones[i]] = i;

	auto key_of = [&](int position, int k) {
		return ((unsigned long long)(k) << 32) | position;
	};

	std::function<int(int, int)> dp = [&](int position, int k) {
		if (position == n - 1)
			return 1;
		const auto key = key_of(position, k);
		if (can_jump.count(key))
			return can_jump[key];
		int ret = 0;
		for (int i = -1; i <= 1; ++i) {
			if (k + i <= 0 || !rev.count(stones[position] + k + i))
				continue;
			ret |= dp(rev[stones[position] + k + i], k + i);
		}
		return can_jump[key] = ret;
	};

	return dp(1, 1);
}
