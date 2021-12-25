#include <vector>
#include <iostream>
#include <set>
/*
class Solution {
public:
	const static int UPPER_BOUND = 14;

	static bool set(int LV, int POS, bool** const vis) {
		std::printf("Setting LV[%d] POS[%d]\n", LV, POS);
		vis[LV][POS] = true;
		for (; LV < UPPER_BOUND; ++LV) {
			POS = (POS >> 1) << 1;
			if (vis[LV][POS] && vis[LV][1 + POS]) {
				std::printf("Merging LV[%d] POS[%d, %d]\n", LV, POS, POS + 1);
				vis[1 + LV][POS >>= 1] = true;
			} else break;
		}
		return true;
	}

	// Fill [L, R)
	static bool fill(const int L, const int R, bool** const vis) {
		std::printf("Filling [%d, %d)\n", L, R);
		if (L == R - 1) {
			// return vis[0][L] = true;
			return set(0, L, vis);
		}
		int LV = UPPER_BOUND;
		for (int X = L ^ (R - 1); !((1 << --LV) & X););
		const int LB = L & ~((1 << (LV + 1)) - 1); // The lower bound of this block
		const int RU = (L & ~((1 << (LV + 1)) - 1)) | ((1 << (LV + 1)) - 1); // The upper bound of this block
		const int M = LB | (1 << LV++);
		if (vis[LV][LB >> LV]) {
			std::printf("[%d, %d) is previously filled.\n", L, R);
			return true;
		}
		if (L == LB && (R - 1) == RU) {
			std::printf("[%d, %d) is an entire block, mark as filled.\n", L, R);
			// return vis[LV][L >> LV] = true;
			return set(LV, L >> LV, vis);
		} // R is not included
		std::printf("[%d, %d) has to be spilt to [%d, %d) and [%d, %d).\n", L, R, L, M, M, R);
		fill(L, M, vis);
		fill(M, R, vis);
		return true;
	}

	static void recover(bool** const vis, std::vector<std::vector<int>>& ans, int LV = UPPER_BOUND, int L = 0, int U = 0) {
		for (int i = L; i <= U; ++i) {
			if (vis[LV][i]) {
				ans.push_back(std::vector<int> {i << LV, (i + 1) << LV});
				std::printf("[%d, %d) is filled\n", i << LV, (i + 1) << LV);
			} else if (LV) {
				recover(vis, ans, LV - 1, i << 1, (i << 1) + 1);
			}
		}
	}

	static std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
		bool* vis[UPPER_BOUND + 1];
		for (int i = 0; i <= UPPER_BOUND; ++i)
			vis[i] = new bool[1 << (UPPER_BOUND - i)]{};
		for (const auto& i : intervals) {
			fill(i[0], i[1], vis);
		}
		std::vector<std::vector<int>> ret, ans;
		recover(vis, ans);
		auto LEN = ans.size();
		for (const auto& i : ans)
			std::printf("[%d, %d]\n", i[0], i[1]);
		for (int i = 0; i < LEN - 1; ++i) {
			if (ans[i][1] == ans[1 + i][0])
				ans[1 + i][0] = ans[i][0];
			else
				ret.push_back(ans[i]);
		}
		ret.push_back(ans[LEN - 1]);
		for (const auto& i : ret)
			std::printf("[%d, %d]\n", i[0], i[1]);
		for (const auto& i : vis)
			delete[] i;
		return ret;
	}
};
*/

class Solution {
public:
	const static int UPPER_BOUND = 14;
	static bool set(int LV, int POS, bool** const vis) {
		vis[LV][POS] = true;
		for (; LV < UPPER_BOUND; ++LV) {
			POS = (POS >> 1) << 1;
			if (vis[LV][POS] && vis[LV][1 + POS])
				vis[1 + LV][POS >>= 1] = true;
			else break;
		}
		return true;
	}

	// Fill [L, R)
	static bool fill(const int L, const int R, bool** const vis) {
		if (L == R - 1)
			return set(0, L, vis);
		int LV = UPPER_BOUND;
		for (int X = L ^ (R - 1); !((1 << --LV) & X););
		const int LB = L & ~((1 << (LV + 1)) - 1); // The lower bound of this block
		const int RU = (L & ~((1 << (LV + 1)) - 1)) | ((1 << (LV + 1)) - 1); // The upper bound of this block
		const int M = LB | (1 << LV++);
		if (vis[LV][LB >> LV])
			return true;
		if (L == LB && (R - 1) == RU)
			return set(LV, L >> LV, vis);
		fill(L, M, vis);
		fill(M, R, vis);
		return true;
	}

	static void recover(bool** const vis, std::vector<std::vector<int>>& ans, int LV = UPPER_BOUND, int L = 0, int U = 0) {
		for (int i = L; i <= U; ++i)
			if (vis[LV][i])
				ans.push_back(std::vector<int> {i << LV, (i + 1) << LV});
			else if (LV)
				recover(vis, ans, LV - 1, i << 1, (i << 1) + 1);
	}

	static std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
		bool* vis[UPPER_BOUND + 1];
		for (int i = 0; i <= UPPER_BOUND; ++i)
			vis[i] = new bool[1 << (UPPER_BOUND - i)]{};
		std::set<int> s;
		for (const auto& i : intervals) {
			if (i[0] == i[1])
				s.insert(i[0]);
			else
				fill(i[0], i[1], vis);
		}
		std::vector<std::vector<int>> ret, ans;
		recover(vis, ans);
		int LEN = ans.size();
		for (int i = 0; i < LEN - 1; ++i) {
			if (ans[i][1] == ans[1 + i][0])
				ans[1 + i][0] = ans[i][0];
			else
				ret.push_back(ans[i]);
		}
		if (LEN > 0)
			ret.push_back(ans[LEN - 1]);
		auto sit = s.begin();
		for (auto it = ret.begin(); it != ret.end() && sit != s.end(); ++it) {
			if (*sit < (*it)[0]) {
				it = ret.insert(it, std::vector<int>{*sit, *sit});
				++sit;
			} else while (sit != s.end() && *sit <= (*it)[1]) ++sit;
		}
		for (; sit != s.end(); ++sit)
			ret.push_back(std::vector<int>{*sit, *sit});
		for (const auto& i : vis)
			delete[] i;
		return ret;
	}
};

int main() {
	std::vector<std::vector<int>> s {
			{1, 1},
			{3, 3},
			{0, 0},
			{0, 0},
			{1, 1}
			/*
			{2, 6},
			{8, 10},
			{15, 18}
			 */
	};
	Solution::merge(s);
	return 0;
}