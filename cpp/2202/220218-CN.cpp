#include <vector>

class Solution {
public:
	static int findCenter(const std::vector<std::vector<int>>& edges) {
		return edges[0][(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) ? 0 : 1];
	}
};