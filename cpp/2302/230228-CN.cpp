#include <vector>
#include <map>

/**
 * 2363. Merge Similar Items
 *
 * You are given two 2D integer arrays, items1 and items2, representing two sets of items. Each array items has the following properties:
 *
 * items[i] = [valuei, weighti] where valuei represents the value and weighti represents the weight of the ith item.
 * The value of each item in items is unique.
 * Return a 2D integer array ret where ret[i] = [valuei, weighti], with weighti being the sum of weights of all items with value valuei.
 *
 * Note: ret should be returned in ascending order by value.
 */

class Solution {
public:
    static std::vector<std::vector<int>> mergeSimilarItems(const std::vector<std::vector<int>>& items1, const std::vector<std::vector<int>>& items2) {
        std::map<int, int> m;
        for (const auto &item: items1)
            m[item[0]] += item[1];
        for (const auto &item: items2)
            m[item[0]] += item[1];
        std::vector<std::vector<int>> ret;
        std::transform(m.begin(), m.end(), std::back_inserter(ret), [](const auto& x) {
            return std::vector<int>{x.first, x.second};
        });
        return ret;
    }
};
