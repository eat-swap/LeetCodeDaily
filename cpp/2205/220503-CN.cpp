#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

/**
 * 937. Reorder Data in Log Files
 * You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.
 *
 * There are two types of logs:
 *
 * Letter-logs: All words (except the identifier) consist of lowercase English letters.
 * Digit-logs: All words (except the identifier) consist of digits.
 * Reorder these logs so that:
 *
 * The letter-logs come before all digit-logs.
 * The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
 * The digit-logs maintain their relative ordering.
 * Return the final order of the logs.
 */

class Solution {
public:
	static std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs) {
		std::vector<std::string> l, d;
		auto getContent = [](const std::string& str) {
			return str.substr(str.find(' ') + 1);
		};

		for (auto s : logs) {
			(std::any_of(s.begin() + s.find(' '), s.end(), [](char c){ return std::isalpha(c); }) ? &l : &d)->emplace_back(std::move(s));
		}

		std::sort(l.begin(), l.end(), [&](const std::string& x, const std::string& y){
			auto cx = getContent(x), cy = getContent(y);
			return cx == cy ? x < y : cx < cy;
		});
		l.insert(l.end(), d.begin(), d.end());
		return l;
	}
};
