#include <vector>
#include <string>
#include <iostream>

/**
 * 763. Partition Labels
 * You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
 * Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
 * Return a list of integers representing the size of these parts.
 */

class Solution {
public:
    static std::vector<int> partitionLabels(const std::string& s) {
        int n = s.length(), lastSeen[26]{};
        for (int i = 0; i < n; ++i)
            lastSeen[s[i] - 'a'] = i;

        std::vector<int> ret;

        // Each loop, Select [L, R].
        for (int i = 0; i < n;) {
            int L = i, R = i;
            for (int j = i; j <= R; ++j) {
                if (lastSeen[s[j] - 'a'] > j) {
                    R = std::max(R, lastSeen[s[j] - 'a']);
                }
            }
            ret.push_back(R - L + 1);
            i = R + 1;
        }

        return ret;
    }
};

int main() {
    // auto ret = Solution::partitionLabels("ababcbacadefegdehijhklij");
    auto ret = Solution::partitionLabels("eccbbbbdec");
    for (int i : ret)
        std::cout << i << ' ';
    return 0;
}
