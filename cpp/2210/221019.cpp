#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

/**
 * 692. Top K Frequent Words
 *
 * Given an array of strings words and an integer k, return the k most frequent strings.
 * Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
 */

class Solution {
public:
    static std::vector<std::string> topKFrequent(const std::vector<std::string>& words, int k) {
        std::unordered_map<std::string, int> m;
        std::for_each(words.begin(), words.end(), [&](auto&& x) { ++m[x]; });

        auto cmp = [](auto&& x, auto&& y) {
            return (x.second != y.second) ? x.second > y.second : x.first < y.first;
        };

        using PSI = std::pair<std::string, int>;
        std::priority_queue<PSI, std::vector<PSI>, decltype(cmp)> q;
        std::for_each(m.begin(), m.end(), [&](auto&& x) {
            q.push(x);
            if (q.size() > k)
                q.pop();
        });

        std::vector<std::string> ret;
        ret.reserve(k);
        while (!q.empty()) {
            ret.push_back(q.top().first);
            q.pop();
        }

        return ret;
    }
};

int main() {
    return 0;
}
