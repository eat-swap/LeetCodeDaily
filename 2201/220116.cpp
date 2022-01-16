#include <iostream>
#include <vector>

class Solution {
public:
	static int maxDistToClosest(const std::vector<int>& seats) {
		int pos = 0;
		for (; !seats[pos]; ++pos);

		// pos is now the 1st '1'.
		int ret = pos, prev = pos, n = seats.size();
		for (++pos; pos < n; ++pos) {
			if (seats[pos]) {
				ret = ret > (pos - prev) >> 1 ? ret : (pos - prev) >> 1;
				prev = pos;
			}
		}
		return std::max(ret, n - 1 - prev);
	}
};

int main() {
	std::printf("%d\n", Solution::maxDistToClosest({1, 0, 0, 0, 1, 0, 1}));
	return 0;
}