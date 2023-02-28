#include <string>
#include <cstring>

/**
 * 10. Regular Expression Matching
 *
 * Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 */

class Solution {
private:
    int dp[21][21];
    int sl;

    bool f(const char* s, const char* p, int sd = 0, int pd = 0) {
        // Look at table
        if (dp[sd][pd] >= 0)
            return dp[sd][pd];
        // Terminated regex?
        if (!p[pd])
            return dp[sd][pd] = !s[sd];
        // Empty s?
        if (!s[sd])
            return dp[sd][pd] = (!p[pd]) || (p[pd + 1] == '*' && f(s, p, sd, pd + 2));
        // Look ahead
        if (p[pd + 1] != '*')
            return dp[sd][pd] = (p[pd] == '.' || p[pd] == s[sd]) && f(s, p, sd + 1, pd + 1);
        // Contains *
        // Match 0 or all chars.
        for (int nsd = sd; nsd <= this->sl;) {
            if (f(s, p, nsd, pd + 2))
                return dp[sd][pd] = true;
            if (p[pd] != s[nsd++] && p[pd] != '.')
                break;
        }
        return dp[sd][pd] = false;
    }

public:
    bool isMatch(const std::string& s, const std::string& p) {
        std::memset(this->dp, -1, sizeof this->dp);
        this->sl = s.length();
        return f(s.c_str(), p.c_str());
    }
};

