#include <iostream>
#include <vector>

/**
 * 1288. Remove Covered Intervals
 * Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
 * The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
 * Return the number of remaining intervals.
 */

class Solution {
public:
    static int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& x, const std::vector<int>& y) { return (x[1] - x[0]) < (y[1] - y[0]); });
        int n = intervals.size(), ret = n;
        bool* const vis = new bool[n]{};
        for (int i = 0; i < n; ++i) {
            auto const& current = intervals[i];
            for (int j = 0; j < i; ++j) {
                auto const& prev = intervals[j];
                // prev is included in current
                if (!vis[j] && prev[0] >= current[0] && prev[1] <= current[1]) {
                    vis[j] = true;
                    --ret;
                }
            }
        }
        delete[] vis;
        return ret;
    }
};

int main() {
    std::vector<std::vector<int>> args {{1, 4}, {3, 6}, {2, 8}};
    std::cout << Solution::removeCoveredIntervals(args);
    return 0;
}
