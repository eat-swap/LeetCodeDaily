#include <vector>

/**
 * 661. Image Smoother
 * An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).
 * Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.
 */

class Solution {
public:
	static std::vector<std::vector<int>> imageSmoother(const std::vector<std::vector<int>>& img) {
		auto m = img.size(), n = img.front().size();
		int* tmp = new int[n];
		std::vector<std::vector<int>> ret;
		ret.reserve(m);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int cnt = 1, total = img[i][j];
				for (int k = -1; k <= 1; ++k) {
					for (int l = -1; l <= 1; ++l) {
						if (i + k >= 0 && i + k < m && j + l >= 0 && j + l < n && (k || l)) {
							total += img[i + k][j + l];
							++cnt;
						}
					}
				}
				tmp[j] = total / cnt;
			}
			ret.emplace_back(tmp, tmp + n);
		}
		delete[] tmp;
		return ret;
	}
};
