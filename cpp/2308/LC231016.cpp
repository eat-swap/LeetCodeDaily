#include "defs.h"

class LC231016 {
public:
	static std::vector<int> getRow(int rowIndex) noexcept;
};

std::vector<int> LC231016::getRow(int rowIndex) noexcept {
	int row[36] {1};
	int tmp[36] {1};
	for (int i = 0; i < rowIndex; ++i) {
		for (int j = 1; j < 35; ++j)
			tmp[j] = row[j] + row[j - 1];
		std::memcpy(row + 1, tmp + 1, 35 * sizeof(int));
	}
	return {row, row + rowIndex + 1};
}
