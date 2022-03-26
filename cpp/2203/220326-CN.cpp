#include <vector>
#include <string>
#include <numeric>
#include <stdexcept>
#include <algorithm>

/**
 * 682. Baseball Game
 * You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.
 * At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:
 * - An integer x - Record a new score of x.
 * - "+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
 * - "D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
 * - "C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
 * Return the sum of all the scores on the record.
 *
 * 100% STL implementation!
 */

class Solution {
public:
	static int calPoints(std::vector<std::string>& ops) {
		std::vector<int> scores;
		std::for_each(ops.begin(), ops.end(), [&](const std::string& str) {
			int x;
			try {
				x = std::stoi(str);
			} catch (const std::invalid_argument& ignored) {
				switch (str[0]) {
					case '+':
						scores.push_back(*std::prev(scores.end(), 2) + scores.back());
						break;
					case 'C':
						scores.pop_back();
						break;
					case 'D':
						scores.push_back(2 * scores.back());
						break;
					default:;
				}
				return;
			}
			scores.push_back(x);
		});
		return std::accumulate(scores.begin(), scores.end(), 0);
	}
};
