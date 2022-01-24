#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <unordered_set>
#include <set>
#include <unordered_map>

/**
 * 2034. Stock Price Fluctuation
 * You are given a stream of records about a particular stock. Each record contains a timestamp and the corresponding price of the stock at that timestamp.
 *
 * Unfortunately due to the volatile nature of the stock market, the records do not come in order. Even worse, some records may be incorrect. Another record with the same timestamp may appear later in the stream correcting the price of the previous wrong record.
 *
 * Design an algorithm that:
 *
 * Updates the price of the stock at a particular timestamp, correcting the price from any previous records at the timestamp.
 * Finds the latest price of the stock based on the current records. The latest price is the price at the latest timestamp recorded.
 * Finds the maximum price the stock has been based on the current records.
 * Finds the minimum price the stock has been based on the current records.
 * Implement the StockPrice class:
 *
 * StockPrice() Initializes the object with no price records.
 * void update(int timestamp, int price) Updates the price of the stock at the given timestamp.
 * int current() Returns the latest price of the stock.
 * int maximum() Returns the maximum price of the stock.
 * int minimum() Returns the minimum price of the stock.
 */

class StockPrice {
private:
	std::unordered_map<int, int> m;
	std::multiset<int> min;
	int currentTS = -1, currentPrice = -1;
public:
	StockPrice() = default;

	void update(int timestamp, int price) {
		if (timestamp >= currentTS) {
			currentTS = timestamp;
			currentPrice = price;
		}
		if (m.count(timestamp)) {
			min.erase(min.find(m[timestamp]));
		}
		m[timestamp] = price;
		min.insert(price);
	}

	int current() const {
		return currentPrice;
	}

	int maximum() const {
		return *min.rbegin();
	}

	int minimum() const {
		return *min.begin();
	}
};

class StockPriceHashMap {
private:
	int currentTS = -1, currentPrice = -1;
	bool updatedMax = false, updatedMin = false;
	int max = -1, min = 0x7FFFFFFF, maxTS = -1, minTS = -1;
	std::unordered_map<int, int> m;
public:
	StockPriceHashMap() = default;

	void update(int timestamp, int price) {
		if (timestamp >= currentTS) {
			currentTS = timestamp;
			currentPrice = price;
		}
		m[timestamp] = price;
		if (price >= max || maxTS == timestamp)
			updatedMax = true;
		if (price <= min || minTS == timestamp)
			updatedMin = true;
	}

	int current() const {
		return currentPrice;
	}

	int maximum() {
		if (!updatedMax)
			return max;
		updatedMax = false;
		max = -1;
		for (const auto& i : m) {
			if (i.second > max) {
				maxTS = i.first;
				max = i.second;
			}
		}
		return max;
	}

	int minimum() {
		if (!updatedMin)
			return min;
		updatedMin = false;
		min = 0x7FFFFFFF;
		for (const auto& i : m) {
			if (i.second < min) {
				minTS = i.first;
				min = i.second;
			}
		}
		return min;
	}
};

class StockPriceHeap {
	std::vector<std::pair<int, int>> maxHeap, minHeap;
	int currentTS = -1, currentPrice = -1;
	std::unordered_set<int> involvedTS;

	static constexpr inline int father(int n) {
		return ((n + 1) >> 1) - 1;
	}

	static constexpr inline int LChild(int n) {
		return ((n + 1) << 1) - 1;
	}

	static constexpr inline int RChild(int n) {
		return (n + 1) << 1;
	}

public:
	StockPriceHeap() = default;

	void update(int timestamp, int price) {
		if (timestamp >= currentTS) {
			currentTS = timestamp;
			currentPrice = price;
		}

		// Search in minHeap
		auto f = [timestamp, price, this](std::vector<std::pair<int, int>>& heap, auto cmp) {
			int n = heap.size(), pos = n;
			if (!this->involvedTS.count(timestamp)) {
				// insert into heap;
				heap.emplace_back(timestamp, price);
			} else {
				for (int i = 0; i < n; ++i) {
					if (heap[i].first == timestamp) {
						if (heap[i].second == price) {
							// Found not changed, return immediately
							return;
						}
						heap[i].second = price;
						pos = i;
						break;
					}
				}
			}
			// always treat heap as a maximum heap
			// std::make_heap(heap.begin(), heap.end(), cmp);
			while (pos && cmp(heap[father(pos)], heap[pos])) { // swap with father
				std::swap(heap[pos], heap[father(pos)]);
				pos = father(pos);
			}
			while (true) { // swap with children
				int LR = 0;
				if (LChild(pos) < n && cmp(heap[pos], heap[LChild(pos)]))
					LR = -1;
				if (RChild(pos) < n && cmp(LR ? heap[LChild(pos)] : heap[pos], heap[RChild(pos)]))
					LR = 1;
				if (!LR)
					break;
				std::swap(heap[pos], LR == 1 ? heap[RChild(pos)] : heap[LChild(pos)]);
				pos = LR == 1 ? RChild(pos) : LChild(pos);
			}
		};

		f(minHeap, [](const std::pair<int, int>& x, const std::pair<int, int>& y) { return x.second > y.second; });
		f(maxHeap, [](const std::pair<int, int>& x, const std::pair<int, int>& y) { return x.second < y.second; });
		involvedTS.insert(timestamp);
	}

	int current() const {
		return currentPrice;
	}

	int maximum() const {
		return maxHeap[0].second;
	}

	int minimum() const {
		return minHeap[0].second;
	}
};

int main() {
	StockPrice solver;
	/*
	solver.update(1, 10);
	solver.update(2, 5);
	std::cout << "Current = " << solver.current() << std::endl;
	std::cout << "Maximum = " << solver.maximum() << std::endl;
	solver.update(1, 3);
	std::cout << "Maximum = " << solver.maximum() << std::endl;
	solver.update(4, 2);
	std::cout << "Minimum = " << solver.minimum() << std::endl;
	 */

	auto begin = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 20000; ++i) {
		solver.update(i, i);
	}
	for (int i = 1; i <= 10000; ++i) {
		solver.update(i << 1, 1000000000);
		solver.maximum();
		solver.update((i << 1) + 1, 1000000000);
		solver.minimum();
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms\n";
	return 0;
}
