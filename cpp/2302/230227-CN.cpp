#include <vector>

/**
 * 1144. Decrease Elements To Make Array Zigzag
 *
 * Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.
 * An array A is a zigzag array if either:
 * Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
 * OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
 * Return the minimum number of moves to transform the given array nums into a zigzag array.
 */

class Solution {
public:
    static int movesToMakeZigzag(const std::vector<int>& nums) {
        int tmp, c1 = 0, c2 = 0;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            tmp = 0x7FFFFFFF;
            if (i > 0)
                tmp = std::min(tmp, nums[i - 1]);
            if (i + 1 < n)
                tmp = std::min(tmp, nums[i + 1]);
            if (nums[i] >= tmp)
                if (i & 1)
                    c1 += nums[i] - (tmp - 1);
                else
                    c2 += nums[i] - (tmp - 1);
        }
        return std::min(c1, c2);
    }
};
