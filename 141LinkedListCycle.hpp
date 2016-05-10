// 141 Linked List Cycle 
// Given a linked list, determine if it has a cycle in it.
// Follow up:
// Can you solve it without using extra space?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *slow = head, *fast = head->next->next;
        while (true) 
        {
            if (fast == slow) return true;
            if (!fast || !fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
    }
};