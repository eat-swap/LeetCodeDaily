#include <string>
#include <iostream>

class Solution {
public:
	static std::string reversePrefix(std::string word, char ch) {
		std::reverse(word.begin(), std::next(word.begin(), 1 + word.find(ch)));
		return word;
	}
};

int main() {
	std::cout << Solution::reversePrefix("xyxzxe", 'z');
	return 0;
}
