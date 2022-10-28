#include <vector>
#include <string>
#include <unordered_map>

/**
 * 49. Group Anagrams
 *
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 */

class Solution {
private:
	static inline long long h(const std::string& s) {
		long long ret = 0;
		int pos;
		for (char c : s) {
			pos = (c - 'a') << 1;
			ret = (ret & ~(3LL << pos)) | (((ret >> pos & 3) + 1) & 3) << pos;
		}
		return ret | s.length() << 52;
	}

public:
	static std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
		std::unordered_map<long long, std::vector<std::string>*> m;
		for (const std::string& s : strs) {
			auto hash = h(s);
			if (!m.count(hash))
				m[hash] = new std::vector<std::string>;
			m[hash]->push_back(s);
		}
		std::vector<std::vector<std::string>> ret;
		for (const auto& [hash, ptr] : m)
			ret.push_back(std::move(*ptr));
		return ret;
	}
};
