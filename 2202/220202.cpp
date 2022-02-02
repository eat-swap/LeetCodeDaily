#include <vector>
#include <string>

class Solution {
private:
	template<int N>
	static inline constexpr int alter(int n) {
		return n ? -(n == N) : 1;
	}
public:
	static std::vector<int> findAnagrams(const std::string& s, const std::string& p) {
		std::vector<int> ret;
		int np = p.length(), ns = s.length();

		int cnt[26]{};
		for (char ch : p)
			--cnt[ch - 'a'];
		for (int i = std::min(np, ns); i--;)
			++cnt[s[i] - 'a'];

		// Interval: [L, R)
		int C = std::count(cnt, cnt + 26, 0);
		for (int L = 0, R = np; R < ns; ++L, ++R) {
			if (26 == C)
				ret.push_back(L);
			C += alter<-1>(--cnt[s[L] - 'a']) + alter<1>(++cnt[s[R] - 'a']);
		}
		if (26 == std::count(cnt, cnt + 26, 0))
			ret.push_back(ns - np);
		return ret;
	}
};

int main() {
	auto ret = Solution::findAnagrams("cbaebabacd", "abc");
	for (int i : ret)
		std::printf("%d ", i);
	return 0;
}
