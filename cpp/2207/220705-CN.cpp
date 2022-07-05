#include <set>
#include <utility>

/**
 * 729. My Calendar I
 * You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.
 * A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).
 * The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.
 * Implement the MyCalendar class:
 * MyCalendar() Initializes the calendar object.
 * boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 */

class MyCalendar {
private:
	std::set<std::pair<int, int>> s;

public:
	MyCalendar() = default;

	bool book(int start, int end) {
		if (s.empty()) {
			s.insert({start, end});
			return true;
		}
		auto it = s.lower_bound({end, -1});
		if (it == s.begin() || std::prev(it)->second <= start) {
			s.insert({start, end});
			return true;
		}
		return false;
	}
};
