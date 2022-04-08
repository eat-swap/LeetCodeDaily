#include <queue>
#include <vector>

class KthLargest {
private:
	int k;
	std::priority_queue<int, std::vector<int>, std::greater<>> q;
public:
	explicit KthLargest(int k_ = 0, const std::vector<int>& nums = {}) : k(k_) {
		q = std::priority_queue<int, std::vector<int>, std::greater<>>(nums.begin(), nums.end());
		while (q.size() > k)
			q.pop();
	}

	int add(int val) {
		q.push(val);
		if (q.size() > k)
			q.pop();
		return q.top();
	}
};
