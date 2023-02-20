#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>

/**
 * 2347. Best Poker Hand
 *
 * You are given an integer array ranks and a character array suits. You have 5 cards where the ith card has a rank of ranks[i] and a suit of suits[i].
 *
 * The following are the types of poker hands you can make from best to worst:
 *
 * "Flush": Five cards of the same suit.
 * "Three of a Kind": Three cards of the same rank.
 * "Pair": Two cards of the same rank.
 * "High Card": Any single card.
 * Return a string representing the best type of poker hand you can make with the given cards.
 *
 * Note that the return values are case-sensitive.
 */

class Solution {
public:
	static inline std::string bestHand(const std::vector<int>& ranks, const std::vector<char>& suits) {
		if (std::adjacent_find(suits.begin(), suits.end(), std::not_equal_to<>()) == suits.end())
			return "Flush";
		uint8_t cnt[13]{};
		for (auto i : ranks)
			++cnt[i - 1];
		auto m = *std::max_element(cnt, cnt + 13);
		if (m >= 3)
			return "Three of a Kind";
		if (m >= 2)
			return "Pair";
		return "High Card";
	}
};
