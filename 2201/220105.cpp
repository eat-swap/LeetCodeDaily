#include <vector>
#include <string>
#include <set>
#include <chrono>
#include <iostream>

/**
 * 131. Palindrome Partitioning
 * Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
 *
 * A palindrome string is a string that reads the same backward as forward.
 */

class Solution {
private:
	// isPalindromeS[L][R] -> 0: not visited, 1: is, -1: is not a palindrome.
	int isPalindromeS[17][17]{};
	int hasPalindromeS[17][17]{};
	int sameTo[17]{};
	int strLen = -1;
	const char* str = nullptr;

	/**
	 * whether str[L..R], ranged [L, R], is a palindrome.
	 * @param L Index of the left of the range, included.
	 * @param R ditto
	 * @return -1 -> is not, 1 -> is palindrome.
	 */
	int isPalindrome(int L, int R) {
		if (L > R) return -1;
		if (isPalindromeS[L][R]) return isPalindromeS[L][R];
		switch (R - L) {
			case 0:
				return isPalindromeS[L][R] = 1;
			case 1:
				return isPalindromeS[L][R] = (str[L] == str[R] ? 1 : -1);
			default:
				return isPalindromeS[L][R] = (str[L] == str[R] ? isPalindrome(L + 1, R - 1) : -1);
		}
	}

	int hasPalindrome(int L, int R) {
		if (hasPalindromeS[L][R]) return hasPalindromeS[L][R];
		if (L >= R) return hasPalindromeS[L][R] = -1;
		if (isPalindrome(L, R)) return 1;
		switch (R - L) {
			case 1:
				return hasPalindromeS[L][R] = isPalindrome(L, R);
			default:
				return hasPalindromeS[L][R] = (hasPalindrome(L + 1, R) == 1 || hasPalindrome(L, R - 1) == 1 ? 1 : -1);
		}
	}

	std::vector<std::vector<std::string>> generate(int cnt, char ch, std::vector<std::vector<std::string>>* const dpp) {
		if (dpp[cnt].size()) return dpp[cnt];
		if (cnt == 1) {
			return dpp[1] = {{std::string(1, ch)}};
		}
		std::vector<std::vector<std::string>> ret;
		for (int i = 1; i < cnt; ++i) {
			auto th = generate(cnt - i, ch, dpp);
			for (auto& j : th) {
				j.insert(j.begin(), std::string(i, ch));
			}
			ret.insert(ret.end(), th.begin(), th.end());
		}
		ret.push_back({std::string(cnt, ch)});
		return dpp[cnt] = ret;
	}

	// Partition of [L, R]
	std::vector<std::vector<std::string>> getPartition(int L, int R) {
		// Partition of [L, i], [i + 1, R]
		std::vector<std::vector<std::string>> ret;
		if (sameTo[L] == sameTo[R]) {
			int cnt = R - L + 1;
			std::vector<std::vector<std::string>> dpp[cnt+3];
			return generate(cnt, str[L], dpp);
		}
		if (hasPalindrome(L, R) != 1) {
			ret = {{}};
			auto& t = ret[0];
			for (int i = L; i <= R; ++i) {
				t.emplace_back(str + i, 1);
			}
			return ret;
		}
		if (isPalindrome(L, R) == 1) {
			ret.push_back({std::string(str + L, R - L + 1)});
		}
		for (int i = L; i < R; ++i) {
			auto left = getPartition(L, i);
			auto right = getPartition(i + 1, R);
			for (const auto& j: left) {
				for (const auto& k: right) {
					ret.push_back(j);
					auto& thisVec = ret.back();
					thisVec.insert(thisVec.end(), k.begin(), k.end());
				}
			}
		}
		std::set<std::vector<std::string>> s;
		s.insert(ret.begin(), ret.end());
		return {s.begin(), s.end()};
	}

public:
	// Partition of [L, R) is all Cartesian Product of [L, M) and [M, R)'s partition.
	std::vector<std::vector<std::string>> partition(const std::string& s) {
		this->strLen = s.length();
		this->str = s.c_str();
		auto t2 = std::chrono::high_resolution_clock::now();

		for (int i = 1; i < this->strLen; ++i) {
			if (str[i] == str[i - 1]) {
				sameTo[i] = sameTo[i - 1];
			} else {
				sameTo[i] = i;
			}
		}

		auto ret = this->getPartition(0, this->strLen - 1);

		auto t3 = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t3 - t2).count() << "ms" << std::endl;
		return ret;
	}
};

int main() {
	Solution solver;
	auto ans = solver.partition("aaaaaaaaaaaaaaaa");
	std::cout << ans.size();
	return 0;
}