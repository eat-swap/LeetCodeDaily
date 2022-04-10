#include <queue>
#include <vector>

/**
 * 703. Kth Largest Element in a Stream
 * Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * Implement KthLargest class:
 * KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
 * int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
 */

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
