#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

/**
 * 1658. Minimum Operations to Reduce X to Zero
 * You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
 * Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
 *
 * Runtime: 179 ms, faster than 94.38% of C++ online submissions for Minimum Operations to Reduce X to Zero.
 * Memory Usage: 98.5 MB, less than 60.71% of C++ online submissions for Minimum Operations to Reduce X to Zero.
 */

class Solution {
public:
	static int minOperations(const std::vector<int>& ns, const int x) {
		const int n = ns.size();
		int sum = std::accumulate(ns.begin(), ns.end(), 0);

		if (sum < x)
			return -1;
		if (sum == x)
			return n;

		int sid = n,
			pid = 0,
			ret = 0x7FFFFFFF;

		// Un-comment this.
		// ns.push_back(0);
		for (; sid-- >= 0; sum -= ns[n - sid - 1]) {
			while (sum < x && pid < n)
				sum += ns[pid++];
			if (sum == x)
				ret = std::min(ret, pid + sid + 1);
		}

		return ret == 0x7FFFFFFF ? -1 : ret;
	}
};

/*
 * Runtime: 215 ms, faster than 81.01% of C++ online submissions for Minimum Operations to Reduce X to Zero.
 * Memory Usage: 107.2 MB, less than 34.90% of C++ online submissions for Minimum Operations to Reduce X to Zero.
 */

class SolutionOld {
public:
	static int minOperations(const std::vector<int>& ns, const int x) {
		int* ps = new int[ns.size() + 1] {};
		int* ss = new int[ns.size() + 1] {};
		const int n = ns.size();

		for (int i = 1; i <= n; ++i)
			ps[i] = ps[i - 1] + ns[i - 1];
		for (int i = 1; i <= n; ++i)
			ss[i] = ss[i - 1] + ns[n - i];

		if (ps[n] < x)
			return -1;
		if (ps[n] == x)
			return n;

		int sid = std::upper_bound(ss, ss + n + 1, x) - ss,
			pid = 0,
			ret = (ss[sid] == x) ? sid : 0x7FFFFFFF;
		for (--sid; sid >= 0; --sid) {
			while (ps[pid] + ss[sid] < x && pid < n)
				++pid;
			if (ps[pid] + ss[sid] == x)
				ret = std::min(ret, pid + sid);
		}

		return ret == 0x7FFFFFFF ? -1 : ret;
	}
};

int main() {
	std::cout << Solution::minOperations({5,2,3,1,1},5) << "\n";
	std::cout << Solution::minOperations({3,2,20,1,1,3},10) << "\n";
	std::cout << Solution::minOperations({1,1},3) << "\n";
	std::cout << Solution::minOperations({1,1,4,2,3},5) << "\n";
	std::cout << Solution::minOperations({5,6,7,8,9},4) << "\n";
	return 0;
}
