// 142 Linked List Cycle II 
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
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

 // Suppose the first meet at step k,the distance between the start node of list and the start node of cycle is s,
 // and the distance between the start node of cycle and the first meeting node is m.
 // Then 2k = (s + m + n1r) = 2(s + m + n2r) ==> s + m = nr. Steps moving from start node to the start of
 // the cycle is just s, moving from m by s steps would be the start of the cycle, covering n cycles.
 // In other words, they meet at the entry of cycle.

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