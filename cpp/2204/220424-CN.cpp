%:include <iostream>
%:include <algorithm>

/**
 * 868. Binary Gap
 * Given a positive integer n, find and return the longest distance between any two adjacent 1's in the binary representation of n. If there are no two adjacent 1's, return 0.
 * Two 1's are adjacent if there are only 0's separating them (possibly no 0's). The distance between two 1's is the absolute difference between their bit positions. For example, the two 1's in "1001" have a distance of 3.
 *
 * Let's try something new today!
 */

class Solution <%
public:
	static int binaryGap(int n) <%
		int ans = 0, current = 1;
		while (not (n bitand 1)) <%
			n >>= 1;
		%>
		if (n == 1) <%
			return 0;
		%>
		for (; n; n >>= 1) <%
			if (n bitand 1) <%
				ans = std::max(ans, current);
				current = 1;
			%> else <%
				++current;
			%>
		%>
		return ans;
	%>
%>;

int main() <%
	std::cout << Solution::binaryGap(22);
	return 0;
%>
