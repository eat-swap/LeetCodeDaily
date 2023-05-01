#include <algorithm>
#include <numeric>
#include <vector>

/**
 * 1491. Average Salary Excluding the Minimum and Maximum Salary
 *
 * You are given an array of unique integers salary where salary[i] is the salary of the ith employee.
 * Return the average salary of employees excluding the minimum and maximum salary. Answers within 1e-5 of the actual answer will be accepted.
 */

class Solution {
public:
	static inline double average(const std::vector<int>&) noexcept;
};

inline double Solution::average(const std::vector<int>& salary) noexcept {
	return (
		std::reduce(salary.begin(), salary.end(), 0.0) -
		*std::min_element(salary.begin(), salary.end()) -
		*std::max_element(salary.begin(), salary.end())
	) / (salary.size() - 2);
}
