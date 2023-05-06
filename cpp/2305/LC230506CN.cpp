#include <algorithm>
#include <string>

/**
 * 1419. Minimum Number of Frogs Croaking
 *
 * You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.
 * Return the minimum number of different frogs to finish all the croaks in the given string.
 * A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.
 */

class LC230506CN {
public:
	static int minNumberOfFrogs(const std::string&) noexcept;
};

int LC230506CN::minNumberOfFrogs(const std::string& croakOfFrogs) noexcept {
	if (croakOfFrogs.length() % 5)
		return -1;
	int cnt[4]{}, total = 0, ret = 0;
	for (char c: croakOfFrogs) {
		switch (c) {
			case 'c':
				++total, ++cnt[0];
				break;
			case 'r':
				if (!cnt[0])
					return -1;
				--cnt[0], ++cnt[1];
				break;
			case 'o':
				if (!cnt[1])
					return -1;
				--cnt[1], ++cnt[2];
				break;
			case 'a':
				if (!cnt[2])
					return -1;
				--cnt[2], ++cnt[3];
				break;
			case 'k':
				if (!cnt[3])
					return -1;
				--cnt[3], --total;
				break;
			default:
				return -1;
		}
		ret = std::max(ret, total);
	}
	return total ? -1 : ret;
}
