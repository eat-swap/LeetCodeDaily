#include <vector>
#include <algorithm>

/**
 * 1605. Find Valid Matrix Given Row and Column Sums
 *
 * You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.
 * Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.
 * Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.
 */

class Solution {
public:
	static std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum, std::vector<int>& colSum) {
		const int rn = rowSum.size(), cn = colSum.size();
		std::vector<std::vector<int>> ret(rn, std::vector<int>(cn));
		for (int rp = 0, cp = 0, inc; rp < rn && cp < cn; ) {
			inc = std::min(rowSum[rp], colSum[cp]);
			ret[rp][cp] = inc;
			rp += !(rowSum[rp] -= inc);
			cp += !(colSum[cp] -= inc);
		}
		return ret;
	}
};


int main() {
	std::vector<int> rs = {3,8}, cs = {4,7};
	auto r = Solution::restoreMatrix(rs, cs);
	for (const auto& i : r) {
		for (const auto& j : i)
			std::printf("%d ", j);
		std::printf("\n");
	}
	return 0;
}