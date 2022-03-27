#include <vector>
#include <algorithm>
#include <iostream>

/**
 * 1337. The K Weakest Rows in a Matrix
 * You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.
 * A row i is weaker than a row j if one of the following is true:
 * - The number of soldiers in row i is less than the number of soldiers in row j.
 * - Both rows have the same number of soldiers and i < j.
 * Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
 *
 * 100%, pure, STL solution!
 */

class Solution {
public:
	static std::vector<int> kWeakestRows(const std::vector<std::vector<int>>& mat, int k) {
		int n = mat.size();
		std::vector<int> idMat(n), ret(n);
		for (int i = 0; i < n; ++i)
			idMat[ret[i] = i] = std::distance(mat[i].begin(), std::lower_bound(mat[i].begin(), mat[i].end(), 0, std::greater<>()));
		std::sort(ret.begin(), ret.end(), [&](int x, int y) {
			return idMat[x] == idMat[y] ? x < y : idMat[x] < idMat[y];
		});
		return {ret.begin(), ret.begin() + k};
	}
};

class SolutionOld {
public:
	static std::vector<int> kWeakestRows(const std::vector<std::vector<int>>& mat, int k) {
		int n = mat.size();
		std::vector<std::pair<int, const std::vector<int>*>> idMat(n);
		for (int i = 0; i < n; ++i)
			idMat[i] = {i, &mat[i]};
		std::sort(idMat.begin(), idMat.end(), [](const std::pair<int, const std::vector<int>*>& x, const std::pair<int, const std::vector<int>*>& y) {
			auto xPos = std::distance(x.second->begin(), std::lower_bound(x.second->begin(), x.second->end(), 0, std::greater<>()));
			auto yPos = std::distance(y.second->begin(), std::lower_bound(y.second->begin(), y.second->end(), 0, std::greater<>()));
			return (xPos == yPos) ? (x < y) : (xPos < yPos);
		});
		std::vector<int> ret(k);
		for (int i = 0; i < k; ++i)
			ret[i] = idMat[i].first;
		return ret;
	}
};

int main() {
	auto ret = Solution::kWeakestRows({{1,1,0,0,0},
									   {1,1,1,1,0},
									   {1,0,0,0,0},
									   {1,1,0,0,0},
									   {1,1,1,1,1}}, 3);
	for (int i : ret)
		std::cout << i << ' ';
	return 0;
}
