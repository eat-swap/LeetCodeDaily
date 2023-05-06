#include <vector>
#include <algorithm>

/**
 * 2106. Maximum Fruits Harvested After at Most K Steps
 *
 * Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array fruits where fruits[i] = [positioni, amounti] depicts amounti fruits at the position positioni. fruits is already sorted by positioni in ascending order, and each positioni is unique.
 * You are also given an integer startPos and an integer k. Initially, you are at the position startPos. From any position, you can either walk to the left or right. It takes one step to move one unit on the x-axis, and you can walk at most k steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.
 * Return the maximum total number of fruits you can harvest.
 */

class LC230504CN {
public:
	static int maxTotalFruits(const std::vector<std::vector<int>>&, int, int) noexcept;
};

constexpr inline int calc_step(int L, int R, int sp) noexcept {
	// Assume that L <= R
	if (R < sp)
		return sp - L;
	if (sp < L)
		return R - sp;
	return std::min(sp - L + (R - sp) * 2, R - sp + (sp - L) * 2);
}

int LC230504CN::maxTotalFruits(const std::vector<std::vector<int>>& f, int sp, int k) noexcept {
	int ret = 0, n = f.size();
	for (int L = 0, R = 0, sumL = 0, sumR = 0; R < n; ++R) {
		for (sumR += f[R][1]; L < R && calc_step(f[L][0], f[R][0], sp) > k; ++L)
			sumL += f[L][1];
		if (calc_step(f[L][0], f[R][0], sp) <= k)
			ret = std::max(ret, sumR - sumL);
	}
	return ret;
}
