#include <vector>
#include <iostream>
#include <unordered_set>

/**
 * 1001. Grid Illumination
 * There is a 2D grid of size n x n where each cell of this grid has a lamp that is initially turned off.
 * You are given a 2D array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. Even if the same lamp is listed more than once, it is turned on.
 * When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.
 * You are also given another 2D array queries, where queries[j] = [rowj, colj]. For the jth query, determine whether grid[rowj][colj] is illuminated or not. After answering the jth query, turn off the lamp at grid[rowj][colj] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowj][colj].
 * Return an array of integers ans, where ans[j] should be 1 if the cell in the jth query was illuminated, or 0 if the lamp was not.
 *
 * Overall time complexity: O(Max{m, n}), m = queries.size, n = lamp.size
 */

class Solution {
private:
	inline static constexpr unsigned long long hash(int x, int y) {
		return (((unsigned long long) x) << 32) + ((unsigned long long) y);
	}

	inline static void unHash(const unsigned long long n, int& x, int& y) {
		y = (n & 0xFFFFFFFFLL);
		x = (n >> 32);
	}

	template<typename T>
	inline static void eraseOne(std::unordered_multiset<T>& s, const T& toErase) {
		s.erase(s.find(toErase));
	}

	inline static int directions[] = {-1, 0, 1};

public:
	static std::vector<int> gridIllumination(int n, const std::vector<std::vector<int>>& lamps, const std::vector<std::vector<int>>& queries) {
		std::unordered_set<unsigned long long> points;
		std::unordered_multiset<int> horizontal, vertical, diagonal, subDiagonal;

		// Time complexity: O(n)
		points.reserve(lamps.size());
		for (const auto& i : lamps) {
			points.insert(hash(i[0], i[1]));
		}

		// Main diagonal: (i - j) is fixed.
		// Sub diagonal:  (i + j) is fixed.
		// Time complexity: O(4 * n) --> O(n)
		int x, y;
		horizontal.reserve(points.size());
		vertical.reserve(points.size());
		diagonal.reserve(points.size());
		subDiagonal.reserve(points.size());
		for (const auto& i : points) {
			unHash(i, x, y);
			horizontal.insert(x);
			vertical.insert(y);
			diagonal.insert(x - y);
			subDiagonal.insert(x + y);
		}

		std::vector<int> ret;
		ret.reserve(queries.size());
		// time complexity: O(m), m = queries.length;
		for (const auto& i : queries) {
			x = i[0];
			y = i[1];

			// check if affected, time complexity = O(1)
			ret.push_back((horizontal.count(x) || vertical.count(y) || diagonal.count(x - y) || subDiagonal.count(x + y)) ? 1 : 0);

			// erase effects, time complexity = O(1)
			for (int dx : directions) {
				for (int dy : directions) {
					if (points.count(hash(x + dx, y + dy))) {
						points.erase(hash(x + dx, y + dy));
						eraseOne(horizontal, x + dx);
						eraseOne(vertical, y + dy);
						eraseOne(diagonal, (x + dx) - (y + dy));
						eraseOne(subDiagonal, (x + dx) + (y + dy));
					}
				}
			}
		}
		return ret;
	}
};

int main() {
	const auto ret = Solution::gridIllumination(5,{{0,0},{0,4}},{{0,4},{0,1},{1,4}});
	for (const auto& i : ret)
		std::cout << i << ' ';
	return 0;
}
