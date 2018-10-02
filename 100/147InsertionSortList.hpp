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

public ListNode insertionSortList(ListNode head) {
        if( head == null ){
            return head;
        }

        ListNode helper = new ListNode(0); //new starter of the sorted list
        ListNode cur = head; //the node will be inserted
        ListNode pre = helper; //insert node between pre and pre.next
        ListNode next = null; //the next node will be inserted
        //not the end of input list
        while( cur != null ){
            next = cur.next;
            //find the right place to insert
            while( pre.next != null && pre.next.val < cur.val ){
                pre = pre.next;
            }
            //insert between pre and pre.next
            cur.next = pre.next;
            pre.next = cur;
            pre = helper;
            cur = next;
        }

        return helper.next;
    }

// improved by reseting pre everytime.
ListNode *insertionSortList(ListNode *head) { 
    if(!head)return NULL;
    ListNode *h=new ListNode(0);
    ListNode *cur=head;
    ListNode *prev=h;
    ListNode *next=NULL;
    while(cur){
        next=cur->next;
        if(!prev||!prev->next||prev->next->val>=cur->val)prev=h;//added this line
        while(prev->next&&prev->next->val<cur->val){
            prev=prev->next;
        }
        cur->next=prev->next;
        prev->next=cur;
        //pre = helper; I erase this line;
        cur=next;
    }
    return h->next;
}