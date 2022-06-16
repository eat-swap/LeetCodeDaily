#include <vector>

/**
 * 1089. Duplicate Zeros
 * Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
 * Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.
 */

class Solution {
public:
	static void duplicateZeros(std::vector<int>& arr) {
		const int n = arr.size();
		int pos = 0, ori = 0;
		for (; ori < n; ++pos)
			ori += arr[pos] ? 1 : 2;
		if (ori > n) { // else: ori == n
			arr[ori = n - 1] = 0;
			--pos;
		}
		--pos;
		for (; ori; --pos)
			if (!(arr[--ori] = arr[pos]))
				arr[--ori] = arr[pos];
	}
};

int main() {
	std::vector<int> s {1,0,2,3,0,4,5,0};
	Solution::duplicateZeros(s);
	return 0;
}
