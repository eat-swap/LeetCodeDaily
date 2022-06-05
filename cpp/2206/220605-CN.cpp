#include <vector>
#include <ctime>
#include <random>

class Solution {
private:
	double radius, x_center, y_center;
	std::mt19937_64 r;

public:
	Solution(double radius, double xCenter, double yCenter) : radius(radius), x_center(xCenter), y_center(yCenter) {
		r = std::mt19937_64(std::time(nullptr));
	}

	std::vector<double> randPoint() {
		double l = double (r()) / std::mt19937_64::max() * radius, d = double (r()) / std::mt19937_64::max() * std::acos(-1.0);
		return {x_center + std::sin(d) * l, y_center + std::cos(d) * l};
	}
};
