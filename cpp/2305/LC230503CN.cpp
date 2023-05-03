#include <string>

/**
 * 1003. Check If Word Is Valid After Substitutions
 *
 * Given a string s, determine if it is valid.
 *
 * A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:
 *
 * Insert string "abc" into any position in t. More formally, t becomes t[left] + "abc" + t[right], where t == t[left] + t[right]. Note that t[left] and t[right] may be empty.
 * Return true if s is a valid string, otherwise, return false.
 */


class LC230503CN {
public:
	static bool isValid(const std::string&) noexcept;
};

int matcher(const char* str) noexcept {
	auto* ptr = str;
	for (int i = 0; i < 3;) {
		if (i + 'a' == *str) {
			// Advance
			++str;
			++i;
		} else if ('a' == *str) {
			int adv = matcher(str);
			if (!adv)
				return 0;
			str += adv;
		} else return 0;
	}
	return str - ptr;
}

bool LC230503CN::isValid(const std::string& s) noexcept {
	for (auto* ptr = s.c_str(); *ptr;)
		if (int adv = matcher(ptr); adv)
			ptr += adv;
		else
			return false;
	return true;
}
