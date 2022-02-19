#include <vector>

/**
 * 2029. Stone Game IX
 * Alice and Bob continue their games with stones. There is a row of n stones, and each stone has an associated value. You are given an integer array stones, where stones[i] is the value of the ith stone.
 * Alice and Bob take turns, with Alice starting first. On each turn, the player may remove any stone from stones. The player who removes a stone loses if the sum of the values of all removed stones is divisible by 3. Bob will win automatically if there are no remaining stones (even if it is Alice's turn).
 * Assuming both players play optimally, return true if Alice wins and false if Bob wins.
 */

class Solution {
public:
	static bool stoneGameIX(const std::vector<int>& stones) {
		int s[3] {
				static_cast<int>(std::count_if(stones.begin(), stones.end(), [](int n){ return n % 3 == 0; })),
				static_cast<int>(std::count_if(stones.begin(), stones.end(), [](int n){ return n % 3 == 1; })),
				static_cast<int>(std::count_if(stones.begin(), stones.end(), [](int n){ return n % 3 == 2; }))
		};

		/**
		 * If now state is '1', next should take '1' and state changes to '2'.
		 * If '2', next should take '2' and state changes to 4 --%3--> '1'.
		 *
		 * If s[0] % 2 == 1, Alice will take what it originally takes.
		 * Otherwise, Alice will take what it not takes originally.
		 *
		 * Why? To make oneself not to fail, one must take the contrary (1 <--> 2)
		 * of the previous take. 2 players means that one should constantly take
		 * the pile which belongs to (in fact, if not, it fails immediately) it.
		 * And consider '3's. Taking them does not change the sum mod 3, just like
		 * a switch to force your opponent to take what originally "belongs to" you.
		 * No one wants to fail. Assume that there is not any '3's, taking the pile
		 * with fewer stones will definitely fail. If possible, one will try its
		 * best to make its opponent to take the more one.
		 *
		 * After the 1st take, the one who take the pile with fewer stones fails.
		 *
		 * When abs(s[1] - s[2]) >= 3, Alice determines what it takes by inspecting s[0].
		 * In this case, Alice wins.
		 *
		 * Then we must consider the possibility of taking all stones.
		 * Since abs(s[1] - s[2]) < 3, it is impossible to trigger rule I and there is no
		 * need to consider "took all but found sum mod 3 == 0". (except s[1] == s[2])
		 * Taking all stones will always result the winning of Bob. Discussions below:
		 *
		 * Case abs(..) == 2:
		 *     Case s[0] % 2 == 0:
		 *         Alice wins: take the fewer --> Bob fails by taking sum mod 3 == 0;
		 *     Else:
		 *         Bob wins: Taking the fewer pile --> Alice takes make sum mod 3 == 0 --> Fails
		 *         Taking the more pile --> Alice takes the last one --> Fails
		 * Case abs(..) == 1:
		 *     Case s[0] % 2 == 0:
		 *         ditto.
		 *     Else:
		 *         ditto.
		 * Case abs(..) == 0:
		 *     Case s[0] % 2 == 0:
		 *         Taking any will result in Bob's failure: taking the last one but sum % 3 == 0.
		 *     Else:
		 *         Taking any will result in Alice's failure: ditto.
		 *
		 * Special: one pile is == 1.
		 * Case s[0] % 2 == 0:
		 *     Alice take the pile with only one stone then wins.
		 * Else:
		 *
		 */
		if ((!s[1] && !s[2]) || (s[0] + s[1] + s[2]) == 1)
			return false;
		if (!s[1] || !s[2]) {
			switch (s[1] ? s[1] : s[2]) {
				case 0:
					// unreachable
				case 1:
				case 2:
					return false;
				default:
					return s[0] & 1;
			}
		}
		if (s[1] == 1 || s[2] == 1) {
			if (!(s[0] & 1))
				return true;
			return (s[1] == 1 ? s[2] : s[1]) > 3;
		}
		switch (std::abs(s[1] - s[2])) {
			case 0:
			case 1:
			case 2:
				return !(s[0] & 1);
			default:
				return true;
		}
		// unreachable
	}
};

int main() {
	std::vector<int> arg(100000, 10000);
	return Solution::stoneGameIX({3, 1, 1, 1});
}
