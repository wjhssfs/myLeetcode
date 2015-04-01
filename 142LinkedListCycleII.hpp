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
       	if (!head) return NULL;
		ListNode *slowP = head;
		ListNode *fastP = head->next;
		while (fastP){
			if (slowP == fastP) break;
			slowP = slowP->next;
			fastP = fastP->next;
			if (fastP == NULL) return NULL;
			fastP = fastP->next;
		}
		if(!fastP) return NULL;
		int loopLength = 0;
		while (loopLength == 0 || slowP != fastP){
			slowP = slowP->next;
			fastP = fastP->next;
			fastP = fastP->next;
			loopLength++;
		}
		slowP = fastP = head;
		while(loopLength--){
		    fastP = fastP->next;
		}
		while(slowP!=fastP){
		    slowP = slowP->next;
			fastP = fastP->next;
		}
		return slowP;
    }
};

class Solution2 {
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
        
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow;
    }
};