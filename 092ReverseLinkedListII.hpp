// 91 Reverse Linked List II 
// Reverse a linked list from position m to n. Do it in-place and in one-pass.
// 
// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
// 
// return 1->4->3->2->5->NULL.
// 
// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0), *ins = &dummy;
        dummy.next = head;
        for (int i = 0; i < m-1; ++i)
            ins = ins->next;
        ListNode *cur = ins->next;
        for (int i = 0; i < n-m; ++i) {
            ListNode *move = cur->next;
            cur->next = move->next;
            move->next = ins->next;
            ins->next = move;
        }
        return dummy.next;
    }
};