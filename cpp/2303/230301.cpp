#include <vector>
#include <cstdint>

/**
 * 912. Sort an Array
 *
 * Given an array of integers nums, sort the array in ascending order and return it.
 * You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
 */

class Solution {
private:
	static inline const int S = 50001;

public:
	static std::vector<int> sortArray(std::vector<int>& nums) {
		const int n = nums.size();
		std::vector<int> ret(n);
		uint16_t bucket[100005]{};
		for (int i : nums)
			++bucket[i + S];
		for (int i = 0, pos = 0; i < 100005; ++i)
			for (int j = 0, ins = i - S; j < bucket[i]; ++j)
				ret[pos++] = ins;
		return ret;
	}
};

int main() {
	return 0;
}
