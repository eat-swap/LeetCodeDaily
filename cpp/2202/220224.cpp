#include <vector>
#include <algorithm>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x = 0, ListNode* next = nullptr) : val(x), next(next) {}
};

/**
 * 148. Sort List
 * Given the head of a linked list, return the list after sorting it in ascending order.
 */
class Solution {
public:
	static ListNode* sortList(ListNode* head) {
		if (!head)
			return nullptr;
		std::vector<ListNode*> arr;
		for (ListNode* ptr = head; ptr; ptr = ptr->next)
			arr.push_back(ptr);
		std::sort(arr.begin(), arr.end(), [](ListNode* x, ListNode* y){ return x->val < y->val; });
		int n = arr.size();
		for (int i = 0; i < n - 1; ++i)
			arr[i]->next = arr[1 + i];
		arr.back()->next = nullptr;
		return arr[0];
	}
};

int main() {
	return 0;
}
