#include <vector>
#include <iostream>

/**
 * 2100. Find Good Days to Rob the Bank
 * You and a gang of thieves are planning on robbing a bank. You are given a 0-indexed integer array security, where security[i] is the number of guards on duty on the ith day. The days are numbered starting from 0. You are also given an integer time.
 * The ith day is a good day to rob the bank if:
 * There are at least time days before and after the ith day,
 * The number of guards at the bank for the time days before i are non-increasing, and
 * The number of guards at the bank for the time days after i are non-decreasing.
 * More formally, this means day i is a good day to rob the bank if and only if security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].
 * Return a list of all days (0-indexed) that are good days to rob the bank. The order that the days are returned in does not matter.
 */

class Solution {
public:
	static std::vector<int> goodDaysToRobBank(const std::vector<int>& security, int time) {
		int n = security.size();
		std::vector<int> ret, isNotIncreasingSince(n), isNotDecreasingSince(n);
		for (int i = 1; i < n; ++i) {
			isNotDecreasingSince[i] = (security[i - 1] <= security[i]) ? isNotDecreasingSince[i - 1] : i;
			isNotIncreasingSince[i] = (security[i - 1] >= security[i]) ? isNotIncreasingSince[i - 1] : i;
		}
		for (int i = time; i < n - time; ++i)
			if (isNotIncreasingSince[i] <= i - time && isNotDecreasingSince[i + time] <= i)
				ret.push_back(i);
		return ret;
	}
};

int main() {
	auto ret = Solution::goodDaysToRobBank({1,2,3,4,5,6},2);
	for (int i : ret)
		std::cout << i << ' ';
}
