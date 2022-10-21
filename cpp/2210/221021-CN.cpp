#include <stack>
#include <utility>
#include <iostream>

/**
 * 901. Online Stock Span
 *
 * Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
 * The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) for which the stock price was less than or equal to today's price.
 * - For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock spans would be [1,1,1,2,1,4,6].
 * Implement the StockSpanner class:
 * - StockSpanner() Initializes the object of the class.
 * - int next(int price) Returns the span of the stock's price given that today's price is price.
 */

class StockSpanner {
private:
	std::stack<std::pair<int, int>> s;
	int pos = 0;

public:
	StockSpanner() = default;

	int next(int price) {
		while (!s.empty() && s.top().first <= price)
			s.pop();
		int ret = pos - (s.empty() ? -1 : s.top().second);
		s.push({price, pos++});
		return ret;
	}
};

int main() {
	StockSpanner s;
	std::cout << s.next(100) << "\n";
	std::cout << s.next(80) << "\n";
	std::cout << s.next(60) << "\n";
	std::cout << s.next(70) << "\n";
	std::cout << s.next(60) << "\n";
	std::cout << s.next(75) << "\n";
	std::cout << s.next(85) << "\n";
	return 0;
}
