#include <vector>
#include <cstring>

/**
 * 322. Coin Change
 * You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
 * Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 * You may assume that you have an infinite number of each kind of coin.
 */

class Solution {
public:
    static int coinChange(const std::vector<int>& coins, int amount) {
        if (!amount)
            return 0;
        int dp[10005];
        std::memset(dp, 0x7F, sizeof dp);
        dp[0] = 0;
        for (int i = 0; i < 10005; ++i)
            for (int j : coins)
                if (i - j >= 0 && dp[i - j] < 0x7F7F7F7F)
                    dp[i] = std::min(dp[i], dp[i - j] + 1);
        return dp[amount] >= 0x7F7F7F7F ? -1 : dp[amount];
    }
};
