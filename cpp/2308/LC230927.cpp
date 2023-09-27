#include <cctype>
#include <string>
#include <vector>
#include <tuple>

#include "defs.h"

std::string LC230927::decodeAtIndex(const std::string& s, int k) {
	std::tuple<int, int, unsigned long long> col[51];
	int level = 0;
	unsigned long long len = 0;
	int begin = 0, end = 0;
	for (char ch : s) {
		if (std::isalpha(ch)) {
			++len;
			++end;
		} else { // num
			col[level++] = {begin, ch ^ 0x30, len *= (ch ^ 0x30)};
			begin = end = end + 1;
		}
		if (len >= k)
			break;
	}
	if (begin < end)
		col[level++] = {begin, 1, len};
	int ck = k - 1;
	for (int i = level - 1; i >= 0; --i) {
		const auto prev_len = i ? std::get<2>(col[i - 1]) : 0ULL;
		const auto& [b, c_dup, cur_len] = col[i];
		if ((ck %= (cur_len / c_dup)) >= prev_len)
			return {s[ck - prev_len + b]};
	}
	return {s[ck]};
}


