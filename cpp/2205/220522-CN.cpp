#include <bitset>
#include <functional>

/**
 * 464. Can I Win
 * In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.
 * What if we change the game so that players cannot re-use integers?
 * For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
 * Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.
 */

class Solution {
public:
	static bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (!desiredTotal)
			return true;
		if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
			return false;

		// ans Key -> bit 19-0: chosen, bit 20: moving | 0 = me, bit -21: cur
		// ans[state] -> Can I (moves first) win with this state?
		std::bitset<1048576> s, vis;

		std::function<bool(int)> dp = [&](int state) {
			if (vis[state])
				return s.test(state);

			int sum = 0;
			for (int i = 0; i < maxChoosableInteger; ++i)
				if (state & (1 << i))
					sum += 1 + i;

			vis.set(state);
			if (sum >= desiredTotal)
				return bool(s[state] = false);

			for (int i = 0; i < maxChoosableInteger; ++i) {
				if (state & (1 << i))
					continue;
				if (!dp(state | (1 << i)))
					return bool(s[state] = true);
			}
			return bool(s[state] = false);
		};

		return dp(0);
	}
};

int main() {
	std::printf("%s\n", Solution::canIWin(6, 16) ? "yes" : "false");
	return 0;
}

