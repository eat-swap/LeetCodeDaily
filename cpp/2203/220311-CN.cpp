#include <vector>
#include <functional>
#include <iostream>

class Solution {
public:
	static int countHighestScoreNodes(const std::vector<int>& parents) {
		auto n = parents.size();
		int* L = new int[n]{};
		int* R = new int[n]{};
		int* sizeOfSubtrees = new int[n]{};

		for (int i = 1; i < n; ++i)
			*(L[parents[i]] ? &R[parents[i]] : &L[parents[i]]) = i;

		std::function<int(int)> getSubtreeSize = [&](int node) {
			if (sizeOfSubtrees[node])
				return sizeOfSubtrees[node];
			int ret = 1;
			if (L[node])
				ret += getSubtreeSize(L[node]);
			if (R[node])
				ret += getSubtreeSize(R[node]);
			return sizeOfSubtrees[node] = ret;
		};

		unsigned long long retMax = 0;
		int ret = -1;
		for (int i = 0; i < n; ++i) {
			int sizeL = 0, sizeR = 0, sizeOther = n - 1;
			if (L[i])
				sizeOther -= (sizeL = getSubtreeSize(L[i]));
			if (R[i])
				sizeOther -= (sizeR = getSubtreeSize(R[i]));
			auto size = static_cast<unsigned long long>(sizeL ? sizeL : 1) * static_cast<unsigned long long>(sizeR ? sizeR : 1) * static_cast<unsigned long long>(sizeOther ? sizeOther : 1);
			if (retMax < size) {
				retMax = size;
				ret = 1;
			} else if (retMax == size) {
				++ret;
			}
		}

		delete[] L;
		delete[] R;
		delete[] sizeOfSubtrees;

		return ret;
	}
};

int main() {
	std::cout << Solution::countHighestScoreNodes({-1,2,0});
	return 0;
}
