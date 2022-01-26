#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <iostream>

namespace std {
	template<>
	struct hash<std::pair<int, int>> {
		inline std::size_t operator()(const std::pair<int, int>& v) const {
			return std::hash<int>()(v.first) ^ std::hash<int>()(v.second);
		}
	};
}

class DetectSquaresOld {
private:
	std::unordered_multiset<std::pair<int, int>> s;
public:
	DetectSquaresOld() = default;

	void add(const std::vector<int>& point) {
		s.insert(std::make_pair(point[0], point[1]));
	}

	int count(const std::vector<int>& point) const {
		int ret = 0;
		// Point 1
		auto p1 = std::make_pair(point[0], point[1]);
		// Point 2's have same X index as Point 1.
		std::vector<std::pair<int, int>> p2s;
		std::copy_if(s.begin(), s.end(), std::back_inserter(p2s), [&](const std::pair<int, int>& v) { return v.first == p1.first && v.second != p1.second; } );
		for (const auto& p2 : p2s) {
			// Now, we know what Point 3 and Point 4 looks like.
			// Point 1 is (x, y)
			// Point 2 is (x, y + dist)
			// Point 3 is (x +/- dist, y + dist)
			// Point 4 is (x +/- dist, y)
			ret += s.count(std::make_pair(p1.first + (p2.second - p1.second), p2.second)) * s.count(std::make_pair(p1.first + (p2.second - p1.second), p1.second));
			ret += s.count(std::make_pair(p1.first - (p2.second - p1.second), p2.second)) * s.count(std::make_pair(p1.first - (p2.second - p1.second), p1.second));
			/*
			ret += std::count_if(s.begin(), s.end(), [&](const std::pair<int, int>& v) {
				// Point 3, +
				return (v.second == p2.second) && (v.first == p1.first + (p2.second - p1.second));
			}) * std::count_if(s.begin(), s.end(), [&](const std::pair<int, int>& v) {
				// Point 4, +
				return (v.second == p1.second) && (v.first == p1.first + (p2.second - p1.second));
			}) + std::count_if(s.begin(), s.end(), [&](const std::pair<int, int>& v) {
				// Point 3, -
				return (v.second == p2.second) && (v.first == p1.first - (p2.second - p1.second));
			}) * std::count_if(s.begin(), s.end(), [&](const std::pair<int, int>& v) {
				// Point 4, -
				return (v.second == p1.second) && (v.first == p1.first - (p2.second - p1.second));
			});
			 */
		}
		return ret;
	}
};

class DetectSquares {
private:
	std::unordered_multiset<int> indexX[1002], indexY[1002];
public:
	DetectSquares() = default;

	void add(const std::vector<int>& point) {
		indexX[point[0]].insert(point[1]);
		indexY[point[1]].insert(point[0]);
	}

	int count(const std::vector<int>& point) const {
		int ret = 0;
		// Point 2's have same X index as Point 1.
		std::unordered_map<int, int> p2s;
		for (const int p2Y : indexX[point[0]]) {
			if (p2Y != point[1]) {
				++p2s[p2Y];
			}
		}
		for (const auto& p2C : p2s) {
			// Now, we know what Point 3 and Point 4 looks like.
			// Point 1 is (x, y)
			// Point 2 is (x, y + dist)
			// Point 3 is (x +/- dist, y + dist)
			// Point 4 is (x +/- dist, y)
			int dist = p2C.first - point[1];
			ret += indexY[p2C.first].count(point[0] + dist) * indexY[point[1]].count(point[0] + dist) * p2C.second;
			ret += indexY[p2C.first].count(point[0] - dist) * indexY[point[1]].count(point[0] - dist) * p2C.second;
		}
		return ret;
	}
};

int main() {
	DetectSquares detectSquares;
	detectSquares.add({3, 10});
	detectSquares.add({11, 2});
	detectSquares.add({3, 2});
	std::cout << std::endl << detectSquares.count({11, 10});
	std::cout << std::endl << detectSquares.count({14, 8});
	detectSquares.add({11, 2});
	std::cout << std::endl << detectSquares.count({11, 10});
	return 0;
}