#include <algorithm>
#include <string>

/**
 * 2409. Count Days Spent Together
 *
 * Alice and Bob are traveling to Rome for separate business meetings.
 * You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.
 * Return the total number of days that Alice and Bob are in Rome together.
 * You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].
 */

class Solution {
	using CSR = std::string const&;
	static int minus(CSR, CSR);
	static int ord(CSR);

public:
	static int countDaysTogether(CSR, CSR, CSR, CSR);
};

int Solution::countDaysTogether(CSR arriveAlice, CSR leaveAlice, CSR arriveBob, CSR leaveBob) {
	if (leaveAlice < arriveBob || leaveBob < arriveAlice)
		return 0;
	return minus(std::min(leaveAlice, leaveBob), std::max(arriveAlice, arriveBob));
}

int Solution::minus(CSR x, CSR y) {
	return ord(x) - ord(y) + 1;
}

int Solution::ord(CSR x) {
	static const int f[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	return f[(x[0] - '0') * 10 + (x[1] - '0') - 1] + (x[3] - '0') * 10 + (x[4] - '0');
}

int main() {
	return 0;
}
