#include <vector>
#include <cstdio>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}

	ListNode(int x) : val(x), next(nullptr) {}

	ListNode(int x, ListNode* next) : val(x), next(next) {}

	~ListNode() { delete this->next; }
};

class Solution {
public:
	static void reorderList(ListNode* head) {
		ListNode* nodes[50005];
		int n = 0;
		do {
			nodes[n++] = head;
		} while ((head = head->next) != nullptr);
		for (int i = 0, j = n - 1; i <= j; ++i, --j) {
			auto* tmp = nodes[i]->next;
			nodes[i]->next = nodes[j];
			nodes[j]->next = nodes[i] == nodes[i]->next || tmp == nodes[j] ? nullptr : tmp;
		}
	}
};

int main() {
	auto* H = new ListNode(1);
	auto* ptr = H;
	for (int i = 2; i <= 17; ++i) {
		ptr->next = new ListNode(i);
		ptr = ptr->next;
	}
	Solution::reorderList(H);
	ptr = H;
	do {
		std::printf("%d ", ptr->val);
	} while ((ptr = ptr->next) != nullptr);
	delete H;
}