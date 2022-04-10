#include <vector>
#include <algorithm>
#include <typeinfo>
#include <iostream>

/**
 * 744. Find Smallest Letter Greater Than Target
 * Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.
 * Note that the letters wrap around.
 * For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
 */

class Solution {
public:
	static char nextGreatestLetter(const std::vector<char>& letters, char target) {
		auto it = std::upper_bound(letters.begin(), letters.end(), target);
		return it == letters.end() ? letters.front() : *it;
	}
};

int main() {
	const char* str = "123";
	std::vector<char> test(str, str + 3);
	auto func = [](const std::vector<char>& v) {
		// MSVC 17:
		// class std::_Vector_const_iterator<class std::_Vector_val<struct std::_Simple_types<char> > >
		std::cout << typeid(v.begin()).name();
	};
	func(test);
	return 0;
}
