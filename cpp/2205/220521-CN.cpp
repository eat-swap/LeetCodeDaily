#include <vector>
#include <unordered_set>

/**
 * 961. N-Repeated Element in Size 2N Array
 * You are given an integer array nums with the following properties:
 * - nums.length == 2 * n.
 * - nums contains n + 1 unique elements.
 * - Exactly one element of nums is repeated n times.
 * Return the element that is repeated n times.
 */

class Solution {
public:
    static int repeatedNTimes(const std::vector<int>& nums) {
        std::unordered_set<int> s;
        for (int i : nums) {
            if (s.count(i))
                return i;
            s.insert(i);
        }
        return -1;
    }
};
