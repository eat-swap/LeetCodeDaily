#include <vector>
#include <string>
#include <cstdio>

class Solution {
public:
    static bool isAlienSorted(const std::vector<std::string>& words, const std::string& order) {
        int dict[256]{};
        for (int i = 0; i < order.length(); ++i) {
            dict[order[i]] = i;
        }

        auto strcmp = [&](const std::string& x, const std::string& y) {
            const int xl = x.length(), yl = y.length(), kl = std::min(xl, yl);
            for (int i = 0; i < kl; ++i)
                if (dict[x[i]] - dict[y[i]])
                    return dict[x[i]] - dict[y[i]];
            return xl - yl;
        };

        for (int i = 1; i < words.size(); ++i)
            if (strcmp(words[i - 1], words[i]) > 0)
                return false;
        return true;
    }
};

int main() {
    std::printf("%s\n", Solution::isAlienSorted({"hello", "leetcode"}, "hlabcdefgijkmnopqrstuvwxyz") ? "yes" : "no");
    return 0;
}
