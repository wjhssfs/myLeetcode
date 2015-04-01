// 143 Reorder List 
// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// 
// You must do this in-place without altering the nodes' values.
// 
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.


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
	void reorderList(ListNode *head) {
		if (!head || !head->next) return;
		ListNode *p1, *p2, *p3;
		p1 = head; p2 = head->next;

		//split list into 2
		while (p2->next){//find the mid point
			p1 = p1->next;
			p2 = p2->next;
			if (p2->next) p2 = p2->next;
		}
		p2 = p1->next;
		p1->next = nullptr; //cut from the 1st list
		p1 = p2; //p1 is head

		//Reverse 2nd list
		p3 = nullptr; //p3 is reversed list head
		p2 = p1->next;
		while (p1){
			p1->next = p3;
			p3 = p1;
			p1 = p2;
			if(p1) p2 = p1->next;
		}
		p2 = p3;
		p1 = head;//p1 pints to list1, p2 points to list2

		//merge 2 list
		while (p1 && p2){
			p3 = p1->next;
			p1->next = p2;
			p1 = p2->next;
			p2->next = p3;
			p2 = p1;
			p1 = p3;
		}
	}
};


class Solution2 {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head->next->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) slow = slow->next;
        ListNode *mid = slow, *cur = slow->next;
        while (cur->next) {
            ListNode *mov = cur->next;
            cur->next = mov->next;
            mov->next = mid->next;
            mid->next = mov;
        }
        cur = head;
        while (cur != mid && mid->next) {
            ListNode *mov = mid->next;
            mid->next = mov->next;
            mov->next = cur->next;
            cur->next = mov;
            cur = cur->next->next;
        }
    }
};