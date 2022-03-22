#include <string>
#include <iostream>

class Solution {
public:
    static std::string getSmallestString(int n, int k) {
        if (n == k)
            return std::string(n, 'a');
        if (k - n < 26)
            return std::string(n - 1, 'a') + static_cast<char>('a' + (k - n));
        return getSmallestString(n - 1, k - 26) + 'z';
    }
};

int main() {
    std::cout << Solution::getSmallestString(5, 73);
    return 0;
}
