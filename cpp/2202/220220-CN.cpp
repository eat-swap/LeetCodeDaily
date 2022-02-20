#include <vector>

/**
 * 717. 1-bit and 2-bit Characters
 * We have two special characters:
 * The first character can be represented by one bit 0.
 * The second character can be represented by two bits (10 or 11).
 * Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.
 */

class Solution {
public:
    static inline bool isOneBitCharacter(const std::vector<int>& bits) {
        int n = bits.size();
        if (n == 1 || bits[n - 2] == 0)
            return true;
        bool vis[1000] {true};
        for (int i = 0; i < n - 2; ++i)
            if (vis[i])
                vis[1 + bits[i] + i] = true;
        return !vis[n - 2];
    }
};

int main() {
    return 0;
}
