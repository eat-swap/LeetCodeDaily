#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

class LC230829 {
public:
	static int bestClosingTime(const std::string&);
};

int LC230829::bestClosingTime(const std::string& c) {
	const std::size_t n = c.size();
	std::vector<int> prefix(n), suffix(n);
	prefix[0] = (c[0] == 'N');
	for (std::size_t i = 1; i < n; ++i)
		prefix[i] = prefix[i - 1] + (c[i] == 'N');
	suffix[n - 1] = (c[n - 1] == 'Y');
	for (std::size_t i = n - 1; i--; )
		suffix[i] = suffix[i + 1] + (c[i] == 'Y');
	std::size_t ret = n, sum = std::count(c.begin(), c.end(), 'N');
	for (std::size_t i = 0; i < n; ++i)
		if (auto s = prefix[i] + suffix[i] - (c[i] == 'N'); s < sum || (s == sum && i < ret))
			sum = s, ret = i;
	return ret;
}
