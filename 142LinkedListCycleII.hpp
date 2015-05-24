// 142 Linked List Cycle II 
// 
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
// 
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        
        if (slow != fast) return NULL;
        
        // l1 is head to cycle length, l2 is cycle length
        // when slow is at the joint, fast is at l1%l2
        // when fast and slow meet, they are at l2 - l1%l2
        // if we start from head, after l1 steps, fast and slow are both at the joint.
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow;
    }
};