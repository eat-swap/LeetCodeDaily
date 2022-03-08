#include <iostream>
#include <cassert>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}
    ~ListNode() { delete this->next; this->next = nullptr; }
};

class Solution {
private:
    /**
     * Solution for problem # 142
     * Refer: 220119.cpp
     * @param head Head of linked "list"
     * @return Pointer to where the cycle begins
     */
    static ListNode* detectCycle(const ListNode* head) {
        if (!(head && head->next))
            return nullptr;
        const auto* fast = head->next->next;
        const auto* slow = head->next;
        for (; fast && fast->next && fast != slow; ) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (!(fast && fast->next))
            return nullptr;
        assert(fast == slow);
        int cycleLength = 1;
        for (fast = fast->next; fast != slow; ++cycleLength, (fast = fast->next));
        fast = slow = head;
        for (int i = 0; i < cycleLength; ++i)
            fast = fast->next;
        if (fast == slow) {
            for (int i = 1; i < cycleLength; ++i)
                fast = fast->next;
        } else {
            while (fast->next != slow->next) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return const_cast<ListNode*>(fast->next);
    }
public:
    static bool hasCycle(ListNode *head) {
        return detectCycle(head) != nullptr;
    }
};