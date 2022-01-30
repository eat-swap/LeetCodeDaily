#include <string>
#include <vector>
#include <unordered_map>

class Solution {
private:
	static std::unordered_map<std::string, int> breakWords(const std::string& s) {
		std::unordered_map<std::string, int> m;
		for (int pos = 0; pos >= 0; (pos = s.find_first_of(' ', pos)), (pos = (pos == -1 ? -1 : pos + 1))) {
			++m[s.substr(pos, s.find_first_of(' ', pos) - pos)];
		}
		return m;
	};
public:
	static std::vector<std::string> uncommonFromSentences(const std::string& s1, const std::string& s2) {
		auto m1 = breakWords(s1), m2 = breakWords(s2);
		std::vector<std::string> ret;
		for (const auto& i : m1)
			if (i.second == 1 && !m2.count(i.first))
				ret.push_back(i.first);
		for (const auto& i : m2)
			if (i.second == 1 && !m1.count(i.first))
				ret.push_back(i.first);
		return ret;
	}
};

int main() {
	auto ret = Solution::uncommonFromSentences("this apple is sweet", "this apple is sour");
	return 0;
}
