// 21 Merge Two Sorted Lists 
// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head=NULL, *tail=NULL;
        while(l1 && l2){
            if(l1->val > l2->val) swap(l1,l2);
            if(!head) head = tail = l1;
            else{
                tail->next = l1;
                tail = l1;
            }
            l1 = l1->next;
        }
        if(l2) swap(l1, l2);
        if(!head) return l1;
        else tail->next = l1;
        return head;
    }
};


class Solution2 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head(0), *cur = &head;
        while (l1 && l2) 
        {
            ListNode **min = l1->val < l2->val ? &l1 : &l2;
            cur->next = *min;
            cur = cur->next;
            *min = (*min)->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head.next;
    }
};
