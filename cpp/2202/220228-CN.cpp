#include <vector>
#include <cstring>
#include <iostream>

/**
 * 1601. Maximum Number of Achievable Transfer Requests
 * We have n buildings numbered from 0 to n - 1. Each building has a number of employees. It's transfer season, and some employees want to change the building they reside in.
 * You are given an array requests where requests[i] = [from[i], to[i]] represents an employee's request to transfer from building fromi to building toi.
 * All buildings are full, so a list of requests is achievable only if for each building, the net change in employee transfers is zero. This means the number of employees leaving is equal to the number of employees moving in. For example if n = 3 and two employees are leaving building 0, one is leaving building 1, and one is leaving building 2, there should be two employees moving to building 0, one employee moving to building 1, and one employee moving to building 2.
 * Return the maximum number of achievable requests.
 */

class Solution {
public:
	static int maximumRequests(int n, const std::vector<std::vector<int>>& requests) {
		int reqCnt = requests.size();
		int status[n], zeroCnt, ret = 0, lim = (1 << reqCnt);
		for (int i = 0; i < lim; ++i) {
			std::memset(status, 0, sizeof status);
			zeroCnt = n;
			for (int j = 0; j < reqCnt; ++j) {
				if (!(i & (1 << j)))
					continue;
				switch (--status[requests[j][0]]) {
					case 0:
						++zeroCnt;
						break;
					case -1:
						--zeroCnt;
						break;
					default:;
				}
				switch (++status[requests[j][1]]) {
					case 0:
						++zeroCnt;
						break;
					case 1:
						--zeroCnt;
						break;
					default:;
				}
			}
			if (zeroCnt == n) {
				int t = 0;
				for (int j = i; j; j >>= 1)
					if (j & 1)
						++t;
				ret = std::max(ret, t);
			}
		}
		return ret;
	}
};

int main() {
	std::cout << Solution::maximumRequests(5, {{0, 1}, {1,0},{0,1},{1,2},{2,0},{3,4}});
	return 0;
}
