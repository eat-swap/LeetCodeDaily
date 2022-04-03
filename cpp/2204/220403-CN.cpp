#include <vector>
#include <algorithm>
#include <typeinfo>
#include <iostream>

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
