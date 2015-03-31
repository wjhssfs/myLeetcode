// 148 Sort List 
// 
// Tags:{Linked List, Sort}
// 
// Sort a linked list in O(n log n) time using constant space complexity.

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
	ListNode *sortList(ListNode *head) {
		ListNode *vhead =new ListNode(0);
		vhead->next = head;

		int mergeSize = 1;
		ListNode *p1, *p2, *p3;

		bool done;
		do 	{
			done = true;
			p3 = vhead;
			while (p3->next){
				p1 = p2 = p3;
				int i = mergeSize;
				int j = mergeSize * 2;
				while (p2->next && i--) p2 = p2->next;
				if (!p2->next) break;
				done = false;
				while (p3->next && j--) p3 = p3->next;
				merge(p1, p2, p3);
			}
			mergeSize *= 2;
		} while (!done);
		ListNode *result = vhead->next;
		delete vhead;
		return result;
	}

	void merge(ListNode* preHead1, ListNode* preHead2, ListNode* &preNextNode){
		ListNode *nextNode = preNextNode->next;
		preNextNode->next = 0;
		ListNode *vhead2= preHead2->next;
		preHead2->next = 0;
		ListNode *pInsert = preHead1;
		while (vhead2){
			while (pInsert->next && pInsert->next->val < vhead2->val){ pInsert = pInsert->next;}
			if (!pInsert->next) {
				pInsert->next = vhead2;
				break;
			}
			else{
				ListNode *p = vhead2;
				vhead2 = vhead2->next;
				p->next = pInsert->next;
				pInsert->next = p;
				pInsert = pInsert->next;
			}
		}

		while (pInsert->next) pInsert = pInsert->next;
		pInsert->next = nextNode;
		preNextNode = pInsert;
	}
};
