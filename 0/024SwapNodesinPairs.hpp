// 24 Swap Nodes in Pairs 
// Given a linked list, swap every two adjacent nodes and return its head.
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
// Your algorithm should use only constant space. You may not modify the values
// in the list, only nodes itself can be changed.

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
    ListNode *swapPairs(ListNode *head) {
        return swapPairs_1(head);
    }
    
    ListNode *swapPairs_1(ListNode *head) {
        ListNode dummy(0), *cur = &dummy;
        cur->next = head;
        while (cur->next && cur->next->next)
        {
            ListNode *move = cur->next->next;
            cur->next->next = move->next;
            move->next = cur->next;
            cur->next = move;
            cur = move->next;
        }
        return dummy.next;
    }
    
    ListNode *swapPairs_2(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *first = head, *second = head->next;
        first->next = second->next;
        second->next = first;
        first->next = swapPairs(first->next);
        return second;
    }
};
