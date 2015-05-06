// 82 Remove Duplicates from Sorted List II 
// 
// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// 
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.

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
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode *preHead = new ListNode(0);
		preHead->next = head;
		ListNode *deleteN, *preDupe = preHead;
		while (preDupe->next){
			if (preDupe->next->next){
				if (preDupe->next->val == preDupe->next->next->val){
					while (preDupe->next->next && preDupe->next->val == preDupe->next->next->val){
					    deleteN = preDupe->next;
						preDupe->next = preDupe->next->next;
						delete deleteN;
					}
					deleteN = preDupe->next;
					preDupe->next = preDupe->next->next;
					delete deleteN;
					continue;
				}
			}
			preDupe = preDupe->next;
		}
		ListNode * result = preHead->next;
		delete preHead;
		return result;
	}
};

class Solution2 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        return deleteDuplicates_1(head);
    }
    
    ListNode *deleteDuplicates_1(ListNode *head) {
        ListNode dummy(0), *cur = &dummy;
        dummy.next = head;
        while (cur->next)
        {
            ListNode *node = cur->next;
            int val = node->val;
            if (!node->next || node->next->val != val) {
                cur = cur->next;
                continue;
            }
            while (node && node->val == val) {
                ListNode *del = node;
                node = node->next;
                delete del;
            }
            cur->next = node;
        }
        return dummy.next;
    }
    
    ListNode *deleteDuplicates_2(ListNode *head) {
        if (!head) return NULL;
        if (!head->next || head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        int val = head->val;
        while(head && head->val == val) {
            ListNode *del = head;
            head = head->next;
            delete del;
        }
        return deleteDuplicates(head);
    }
};