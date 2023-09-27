#include <cctype>
#include <string>
#include <vector>
#include <tuple>

#include "defs.h"

std::string LC230927::decodeAtIndex(const std::string& s, int k) {
	std::vector<std::tuple<std::string, int, unsigned long long>> col;
	unsigned long long len = 0;
	std::string buf;
	for (char ch : s) {
		if (std::isalpha(ch)) {
			++len;
			buf += ch;
		} else { // num
			col.emplace_back(buf, ch ^ 0x30, len *= (ch ^ 0x30));
			buf.clear();
		}
		if (len >= k)
			break;
	}
	if (!buf.empty())
		col.emplace_back(buf, 1, len);
	const int level = col.size();
	int ck = k - 1;
	for (int i = level - 1; i >= 0; --i) {
		const auto prev_len = i ? std::get<2>(col[i - 1]) : 0ULL;
		const auto& [c_str, c_dup, cur_len] = col[i];
		ck %= (cur_len / c_dup);
		if (ck >= prev_len)
			return {c_str[ck - prev_len]};
	}
	return {std::get<0>(col[0])[ck]};
}


