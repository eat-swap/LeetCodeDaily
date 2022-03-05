#include <vector>
#include <set>
#include <iostream>

/**
 * 740. Delete and Earn
 * You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
 * Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
 * Return the maximum number of points you can earn by applying the above operation some number of times.
 */

class Solution {
private:
	inline static const int maxV = 10002;
public:
	static int deleteAndEarn(const std::vector<int>& nums) {
		int cnt[maxV]{}, val[maxV]{}, ans[maxV]{};
		for (int i : nums)
			++cnt[i];
		for (int i = 2; i < maxV; ++i)
			val[i] = cnt[i] * i;
		ans[1] = val[1] = cnt[1];
		for (int i = 2; i < maxV; ++i)
			ans[i] = std::max(ans[i - 1], val[i] + ans[i - 2]);
		return ans[maxV - 1];
	}
};

int main() {
	std::cout << Solution::deleteAndEarn({1,1,1,2,4,5,5,5,6});
	return 0;
}
