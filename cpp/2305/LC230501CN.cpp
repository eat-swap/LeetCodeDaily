#include <algorithm>
#include <forward_list>
#include <functional>
#include <vector>

/**
 * 1376. Time Needed to Inform All Employees
 *
 * A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.
 * Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.
 * The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.
 * The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).
 * Return the number of minutes needed to inform all the employees about the urgent news.
 */

class LC230501CN {
public:
	using CVIR = const std::vector<int>&;
	static int numOfMinutes(int, int, CVIR, CVIR);
};

int LC230501CN::numOfMinutes(int n, int headID, CVIR manager, CVIR informTime) {
	std::vector<int> ans(n, -1);
	ans[headID] = 0;
	std::function<int(int)> dp = [&](int cur) {
		return ans[cur] >= 0 ? ans[cur] : ans[cur] = dp(manager[cur]) + informTime[manager[cur]];
	};
	int ret = 0;
	for (int i = 0; i < n; ++i)
		ret = std::max(ret, dp(i));
	return ret;
}
