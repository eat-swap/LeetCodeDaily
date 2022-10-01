#include <string>
#include <cstring>
#include <iostream>

/**
 * 91. Decode Ways
 *
 * A message containing letters from A-Z can be encoded into numbers using the following mapping:
 *
 * 'A' -> "1"
 * 'B' -> "2"
 * ...
 * 'Z' -> "26"
 * To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
 *
 * "AAJF" with the grouping (1 1 10 6)
 * "KJF" with the grouping (11 10 6)
 * Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
 *
 * Given a string s containing only digits, return the number of ways to decode it.
 *
 * The test cases are generated so that the answer fits in a 32-bit integer.
 */

class Solution {
private:
    int ans[105]{};

    int help(const char* const t, int pos = 0) {
        if (ans[pos] != -1)
            return ans[pos];
        const char* const s = t + pos;
        if (!*s)
            return 1;
        if ('0' == *s)
            return 0;
        int ret = help(t, pos + 1);
        if (10 * (s[0] ^ 48) + (s[1] ^ 48) <= 26)
            ret += help(t, pos + 2);
        return ans[pos] = ret;
    }
public:
    int numDecodings(const std::string& s) {
        std::memset(ans, -1, sizeof ans);
        return help(s.c_str());
    }
};

int main() {
    Solution s;
    std::cout << s.numDecodings("111111111111111111111111111111111111111111111");
    return 0;
}
