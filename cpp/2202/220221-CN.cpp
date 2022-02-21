#include <string>
#include <queue>

/**
 * 838. Push Dominoes
 * There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
 * After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
 * When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
 * For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
 * You are given a string dominoes representing the initial state where:
 * dominoes[i] = 'L', if the ith domino has been pushed to the left,
 * dominoes[i] = 'R', if the ith domino has been pushed to the right, and
 * dominoes[i] = '.', if the ith domino has not been pushed.
 * Return a string representing the final state.
 */

class Solution {
public:
	std::string pushDominoes(const std::string& dominoes) {
		std::queue<int> q;
		int n = dominoes.length();

		int result[100005]{}, lastModified[100005]{};

		for (int i = 0; i < n; ++i) {
			if ('.' != dominoes[i]) {
				q.push(i);
				q.push(1);
				lastModified[i] = 1;
				result[i] = ((dominoes[i] == 'L') ? -1 : 1);
			}
		}

		while (!q.empty()) {
			int pos = q.front();
			q.pop();
			int tP = q.front();
			q.pop();

			if (pos && (lastModified[pos - 1] == tP + 1 || !lastModified[pos - 1]) && result[pos] < 0) {
				if (!lastModified[pos - 1]) {
					q.push(pos - 1);
					q.push(lastModified[pos - 1] = tP + 1);
				}
				--result[pos - 1];
			} else if (pos < n - 1 && (lastModified[pos + 1] == tP + 1 || !lastModified[pos + 1]) && result[pos] > 0) {
				if (!lastModified[pos + 1]) {
					q.push(pos + 1);
					q.push(lastModified[pos + 1] = tP + 1);
				}
				++result[pos + 1];
			}
		}

		std::string ret;
		ret.reserve(n);
		for (int i = 0; i < n; ++i) {
			ret.push_back(result[i] ? (result[i] > 0 ? 'R' : 'L') : '.');
		}
		return ret;
	}
};

int main() {
	// Tested in C#.
	return 0;
}
