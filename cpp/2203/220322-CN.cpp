#include <string>

/**
 * 2038. Remove Colored Pieces if Both Neighbors are the Same Color
 * There are n pieces arranged in a line, and each piece is colored either by 'A' or by 'B'. You are given a string colors of length n where colors[i] is the color of the ith piece.
 *
 * Alice and Bob are playing a game where they take alternating turns removing pieces from the line. In this game, Alice moves first.
 *
 * Alice is only allowed to remove a piece colored 'A' if both its neighbors are also colored 'A'. She is not allowed to remove pieces that are colored 'B'.
 * Bob is only allowed to remove a piece colored 'B' if both its neighbors are also colored 'B'. He is not allowed to remove pieces that are colored 'A'.
 * Alice and Bob cannot remove pieces from the edge of the line.
 * If a player cannot make a move on their turn, that player loses and the other player wins.
 * Assuming Alice and Bob play optimally, return true if Alice wins, or return false if Bob wins.
 */

class Solution {
public:
	static bool winnerOfGame(const std::string& colors) {
		char state = 'A';
		int A = 0, B = 0, cnt = 0;
		for (char ch : colors) {
			if (ch == state)
				++cnt;
			else {
				*((state ^= 3) == 'B' ? &A : &B) += std::max(cnt - 2, 0);
				cnt = 1;
			}
		}
		if (cnt > 2)
			*(state == 'B' ? &B : &A) += cnt - 2;
		return A > B;
	}
};

int main() {
	Solution::winnerOfGame("AAAABBBB");
	return 0;
}
