#include <algorithm>
#include <string>

class LC230505 {
public:
	static int maxVowels(const std::string&, int) noexcept;
};

constexpr inline int verdict(char ch) noexcept {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int LC230505::maxVowels(const std::string& s, int k) noexcept {
	const int n = s.length();
	int qualified = 0;
	for (int i = 0; i < k; ++i)
		qualified += verdict(s[i]);
	int ret = qualified;
	for (int i = k; i < n; ++i)
		ret = std::max(ret, qualified += verdict(s[i]) - verdict(s[i - k]));
	return ret;
}
