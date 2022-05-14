#include <vector>
#include <string>
#include <array>
#include <cstdio>
#include <unordered_map>
#include <iostream>

struct int128Hash {
	size_t operator()(__int128 x) const {
		return size_t((x & (unsigned long long)(-1)) ^ (x >> 64));
	}
};

/**
 * 691. Stickers to Spell Word
 * We are given n different types of stickers. Each sticker has a lowercase English word on it.
 * You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
 * Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.
 * Note: In all test cases, all words were chosen randomly from the 1000 most common US English words, and target was chosen as a concatenation of two random words.
 */

class Solution {
private:
	// param1 (larger) contains param2
	static bool contains(__int128 x, __int128 y) {
		for (; x || y; (x >>= 4), (y >>= 4))
			if ((x & 0xF) < (y & 0xF))
				return false;
		return true;
	}

	// Adds to specific position
	static void add(__int128& x, int idx, __int128 offset = 1) {
		x += (offset << (idx << 2));
	}

	static void set(__int128& x, int idx, __int128 target = 0) {
		x = (x & ~(__int128(15) << (idx << 2))) | (target << (idx << 2));
	}

	// Get the 4-bit field of specific location
	static int get(__int128 x, int idx) {
		return 0xF & (x >> (idx << 2));
	}

	// == x - y
	static __int128 eliminate(__int128 x, __int128 y) {
		for (int i = 0; i < 26; ++i) {
			if (get(x, i) <= get(y, i))
				set(x, i);
			else
				set(x, i, get(x, i) - get(y, i));
		}
		return x;
	}

	std::vector<__int128> s;
	__int128 t = 0;

	std::unordered_map<__int128, int, int128Hash> d;

	int dp(__int128 state) {
		if (!state)
			return 0;
		if (d.count(state))
			return d[state];

		int ans = 0x6FFFFFFF;
		for (const auto& subset : s) {
			auto nx = eliminate(state, subset);
			if (nx < state)
				ans = std::min(ans, 1 + dp(nx));
		}

		return d[state] = ans;
	}

public:
	int minStickers(const std::vector<std::string>& stickers, const std::string& target) {
		s.reserve(stickers.size());
		for (const auto& str : stickers) {
			__int128 cur = 0;
			for (const auto ch : str)
				add(cur, ch - 'a');
			s.push_back(cur);
		}
		for (const auto ch : target)
			add(t, ch - 'a');

		auto ans = dp(t);
		return ans > 3 + target.length() ? -1 : ans;
	}
};

int main() {
	std::printf("%zd\n", sizeof(std::array<uint8_t, 26>));
	std::printf("%zd\n", sizeof(__int128));
	std::unordered_map<__int128, int> m;
	m[__int128(1) << 65] = 10;
	for (const auto [x, y] : m) {
		std::printf("0x%08llX%08llX", *reinterpret_cast<const unsigned long long*>(&x), *(reinterpret_cast<const unsigned long long*>(&x) + 1));
		std::cout << " / " << y << std::endl;
	}

	Solution s;
	auto r = s.minStickers({"with","example","science"}, "thehat");
	std::cout << r << std::endl;

	return 0;
}
