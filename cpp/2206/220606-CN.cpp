#include <map>

/**
 * 732. My Calendar III
 * A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)
 * You are given some events [start, end), after each given event, return an integer k representing the maximum k-booking between all the previous events.
 * Implement the MyCalendarThree class:
 * MyCalendarThree() Initializes the object.
 * int book(int start, int end) Returns an integer k representing the largest integer such that there exists a k-booking in the calendar.
 */

class MyCalendarThree {
private:
	std::map<int, int> m;

public:
	MyCalendarThree() = default;

	int book(int start, int end) {
		// mb: currently, 0 -> idx, the maximum books
		int ans = 0, mb = 0;
		++m[start];
		--m[end];
		for (const auto& [idx, freq] : m)
			ans = std::max(mb += freq, ans);
		return ans;
	}
};