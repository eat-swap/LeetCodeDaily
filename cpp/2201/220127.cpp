#include <vector>
#include <cstdio>

/**
 * 421. Maximum XOR of Two Numbers in an Array
 * Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
 */

class Solution {
private:
	static const int bpoBits = 3;
	static const int bitsPerOperation = 1 << bpoBits;
	inline static constexpr int getBits(int n, int b) {
		return (n >> (b << bpoBits)) & ((1 << bitsPerOperation) - 1);
	}
public:
	// (32 / bitsPerOperation) * n + (2 ^ bitsPerOperation) ^ 2
	static int findMaximumXOR(const std::vector<int>& nums) {
		std::vector<int> bucket[2][1 << bitsPerOperation];
		std::vector<std::pair<std::vector<int>, std::vector<int>>> pool[2]{{{nums, nums}}, {}};
		for (int i = 32 / bitsPerOperation - 1; i >= 0; --i) {
			auto& thisPool = pool[1 & i];
			const auto& thatPool = pool[1 ^ (1 & i)];
			thisPool.clear();

			int maxVal = -1;
			// For any pair of sequences which can pair...
			for (const auto& pair : thatPool) {
				// Clear bucket
				for (auto& j : bucket)
					for (auto& k : j)
						k.clear();

				// Construct bucket
				for (auto& j : pair.first)
					bucket[0][getBits(j, i)].push_back(j);
				for (auto& j : pair.second)
					bucket[1][getBits(j, i)].push_back(j);

				// Find the max possible xor of this pair...
				int thisMax = -1;
				for (int j = 0; j < (1 << bitsPerOperation); ++j) {
					if (bucket[0][j].empty())
						continue;
					for (int k = 0; k < (1 << bitsPerOperation); ++k)
						if (!bucket[1][k].empty() && (j ^ k) > thisMax)
							thisMax = j ^ k;
				}

				// Only the strongest could survive!
				if (thisMax >= maxVal) {
					if (thisMax > maxVal) {
						thisPool.clear();
						maxVal = thisMax;
					}
					// Anything in that pool has the maximum possible xor for processed bits.
					// This pool should be the same.
					for (int j = 0; j < (1 << bitsPerOperation); ++j) {
						if (bucket[0][j].empty() || bucket[1][thisMax ^ j].empty())
							continue;
						thisPool.emplace_back(bucket[0][j], bucket[1][thisMax ^ j]);
					}
				}
			}
		}
		return pool[0][0].first[0] ^ pool[0][0].second[0];
	}
};

int main() {
	std::printf("%d\n", Solution::findMaximumXOR({2604,6991,8010,8260,5136,8770,8568,3021,1621,7303,9289,9855,7267,7872,1163,2605,1438,5683,7245,3647,7977,2361,8355,3215,1784,1189,9334,4099,2467,9342,5512,2823,1254,6315,645,3638,5077,8442,5957,501,8045,1790,7357,7180,8614,2899,3222,2994,228,5662,8421,7060,669,9413,9353,9697,9141,3688,580,8309,7285,4091,9712,3296,5322,7490,4899,6083,9961,2392,685,1862,5664,2667,6414,2888,3624,5495,4677,2932,9942,6013,1235,6733,8609,5504,9181,6886,7822,2125,4800,1760,8632,468,4927,3009,7627,4167,4296,5437}));
	return 0;
}
