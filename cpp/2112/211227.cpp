#include <iostream>

class Solution {
public:
    static int findComplement(int num) {
        unsigned t = 1;
		for (int x = num; x; t <<= 1, x >>= 1);
		return (t - 1) ^ num;
    }
};

int main() {
	std::printf("%d\n", Solution::findComplement(9));
}