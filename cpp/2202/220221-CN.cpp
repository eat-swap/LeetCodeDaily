#include <string>
#include <queue>

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