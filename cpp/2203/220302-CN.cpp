#include <string>
#include <iostream>

/**
 * 564. Find the Closest Palindrome
 * Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
 * The closest is defined as the absolute difference minimized between two integers.
 */

class Solution {
private:
	static inline constexpr unsigned long long diffULL(unsigned long long x, unsigned long long y) {
		return std::max(x, y) - std::min(x, y);
	}

	static inline constexpr unsigned long long gen1001(unsigned long long n) {
		int digits = 1;
		for (auto i = n; i > 9; i /= 10)
			++digits;
		unsigned long long ret = 1;
		for (int i = 0; i < digits; ++i)
			ret *= 10;
		return ret + 1;
	}

	static inline constexpr unsigned long long gen999(unsigned long long n) {
		int digits = 1;
		for (auto i = n; i > 9; i /= 10)
			++digits;
		unsigned long long ret = 1;
		for (int i = 1; i < digits; ++i)
			ret *= 10;
		return ret - 1;
	}

public:
	static std::string nearestPalindromic(const std::string& n) {
		auto nNum = std::stoull(n);
		if (nNum <= 10)
			return std::to_string(nNum - 1);
		else if (nNum == 11)
			return "9";
		else if (nNum <= 16)
			return "11";
		else if (nNum <= 26)
			return "22";

		auto nLen = n.length();
		if (nLen & 1) {
			auto absMin = 0xFFFFFFFFFFFFFFFFULL;
			std::string ans;
			for (int i = -1; i <= 1; ++i) {
				std::string prefix = n.substr(0, nLen >> 1);
				std::string thisNumStr = prefix;
				thisNumStr.push_back(std::isdigit(n[nLen >> 1] + i) ? (n[nLen >> 1] + i) : n[nLen >> 1]);
				thisNumStr.insert(thisNumStr.end(), prefix.rbegin(), prefix.rend());
				auto thisNum = std::stoull(thisNumStr);
				if (thisNum == nNum)
					continue;
				if (diffULL(thisNum, nNum) < absMin || (diffULL(thisNum, nNum) == absMin && thisNum < std::stoull(ans))) {
					absMin = diffULL(thisNum, nNum);
					ans = thisNumStr;
				}
			}

			auto retNum = std::stoull(ans);
			if (!absMin || (gen1001(nNum) != nNum && (diffULL(gen1001(nNum), nNum) < absMin || (diffULL(gen1001(nNum), nNum) == absMin && gen1001(nNum) < retNum)))) {
				absMin = diffULL(gen1001(nNum), nNum);
				retNum = gen1001(nNum);
			}

			if (!absMin || (gen999(nNum) != nNum && (diffULL(gen999(nNum), nNum) < absMin || (diffULL(gen999(nNum), nNum) == absMin && gen999(nNum) < retNum)))) {
				retNum = gen999(nNum);
			}

			return std::to_string(retNum);
		} else {
			auto prefixNum = std::stoull(n.substr(0, nLen >> 1)), absMin = 0xFFFFFFFFFFFFFFFFULL;
			std::string ans;
			for (int i = -1; i <= 1; ++i) {
				auto thisPrefix = std::to_string(prefixNum + i);
				auto thisNumStr = thisPrefix;
				thisNumStr.insert(thisNumStr.end(), thisPrefix.rbegin(), thisPrefix.rend());
				auto thisNum = std::stoull(thisNumStr);
				if (thisNum == nNum)
					continue;
				if (diffULL(thisNum, nNum) < absMin || (diffULL(thisNum, nNum) == absMin && thisNum < std::stoull(ans))) {
					absMin = diffULL(thisNum, nNum);
					ans = thisNumStr;
				}
			}

			auto retNum = std::stoull(ans);
			if (!absMin || (gen1001(nNum) != nNum && (diffULL(gen1001(nNum), nNum) < absMin || (diffULL(gen1001(nNum), nNum) == absMin && gen1001(nNum) < retNum)))) {
				absMin = diffULL(gen1001(nNum), nNum);
				retNum = gen1001(nNum);
			}

			if (!absMin || (gen999(nNum) != nNum && (diffULL(gen999(nNum), nNum) < absMin || (diffULL(gen999(nNum), nNum) == absMin && gen999(nNum) < retNum)))) {
				retNum = gen999(nNum);
			}

			return std::to_string(retNum);
		}
	}
};

int main() {
	std::cout << Solution::nearestPalindromic("12389");
}
