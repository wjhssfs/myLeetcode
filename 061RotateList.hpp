// 61 Rotate List 
// Given a list, rotate the list to the right by k places, where k is non-negative.
// 
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (k <= 0) return head;
        ListNode *p1 = head, *pt;
        int len = 0;
        while (p1){
            pt = p1;
            p1 = p1->next;
            len++;
        }
        if (len <= 1) return head;
        pt->next = head;
        int shiftL = len - (k%len);
        p1 = head;
        while (--shiftL)  p1 = p1->next;
        head = p1->next;
        p1->next = NULL;
        return head;
    }
};