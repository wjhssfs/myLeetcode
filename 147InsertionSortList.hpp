// 147 Insertion Sort List
// Sort a linked list using insertion sort.

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
    ListNode *insertionSortList(ListNode *head) {
        ListNode vHead(0);
        vHead.next = head;
        ListNode *pPreInsert, *pPreNext;
        pPreNext = &vHead;
        while (pPreNext->next)
        {
            pPreInsert = &vHead;
            while (pPreInsert != pPreNext)
            {
                if (pPreInsert->next->val > pPreNext->next->val)
                {
                    ListNode *cur = pPreNext->next;
                    pPreNext->next = pPreNext->next->next;
                    cur->next = pPreInsert->next;
                    pPreInsert->next = cur;
                    break;
                }
                else
                {
                    pPreInsert = pPreInsert->next;
                }
            }
            if (pPreInsert == pPreNext)
                pPreNext = pPreNext->next;
        }
        return vHead.next;
    }
};