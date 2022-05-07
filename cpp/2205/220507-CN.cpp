#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <iostream>

/**
 * 433. Minimum Genetic Mutation
 * A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
 * Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.
 * For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
 * There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
 * Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.
 * Note that the starting point is assumed to be valid, so it might not be included in the bank.
 */

class Solution {
private:
	static int strToInt(const std::string& str) {
		int ans = 0;
		for (char ch : str) {
			ans <<= 2;
			switch (ch) {
				case 'A':
					break; // ans += 0;
				case 'C':
					ans += 1;
					break;
				case 'G':
					ans += 2;
					break;
				case 'T':
					ans += 3;
					break;
				default:
					return -1;
			}
		}
		return ans;
	}

	static inline const char* map = "ACGT";

	static std::string intToStr(int x) {
		return std::string().append(1, map[(x >> 14) & 3]).append(1, map[(x >> 12) & 3]).append(1, map[(x >> 10) & 3]).append(1, map[(x >> 8) & 3]).append(1, map[(x >> 6) & 3]).append(1, map[(x >> 4) & 3]).append(1, map[(x >> 2) & 3]).append(1, map[x & 3]);
	}

public:
	static int minMutation(const std::string& start, const std::string& end, const std::vector<std::string>& bank) {
		int s = strToInt(start), e = strToInt(end);
		std::unordered_set<int> iBank;
		iBank.reserve(bank.size());
		std::for_each(bank.begin(), bank.end(), [&](const std::string& str) { iBank.insert(strToInt(str)); });

		if (!iBank.count(e))
			return -1;

		std::queue<int> q;
		std::bitset<65536> vis;
		q.push(s);
		q.push(0);
		vis.set(s);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			int dist = q.front();
			q.pop();
			for (int offset = 0; offset < 16; offset += 2) {
				for (int i = 0; i < 4; ++i) {
					int nx = (x & ~(3 << offset)) | (i << offset);
					if (nx == x || !iBank.count(nx) || vis.test(nx))
						continue;
					if (nx == e)
						return dist + 1;
					q.push(nx);
					q.push(dist + 1);
					vis.set(nx);
				}
			}
		}
		return -1;
	}
};

int main() {
	std::cout << Solution::minMutation("AGCAAAAA", "GACAAAAA", {"AGTAAAAA","GGTAAAAA","GATAAAAA","GACAAAAA"});
	return 0;
}
