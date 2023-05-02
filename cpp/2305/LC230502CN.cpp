#include <unordered_set>
#include <vector>

class LC230502CN {
public:
	static std::vector<int> powerfulIntegers(int, int, int) noexcept;
};

std::vector<int> LC230502CN::powerfulIntegers(int x, int y, int bound) noexcept {
	if (bound < 2)
		return {};
	if (x < y)
		std::swap(x, y);
	if (x <= 1)
		return {2};
	std::unordered_set<int> s { 2 };
	for (int ix = 1; ix + 1 <= bound; ix *= x) {
		s.insert(ix + 1);
		if (y <= 1)
			continue;
		for (int iy = 1; ix + iy <= bound; iy *= y)
			s.insert(ix + iy);
	}
	return {s.begin(), s.end()};
}
