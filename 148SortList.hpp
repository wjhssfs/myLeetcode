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
        return sortLinkedList(head, getLength(head));
    }
    
    // Iterative, const space
   	ListNode *sortListIterative(ListNode *head) {
		ListNode dummy{ 0 };
		dummy.next = head;

		int len = getLength(head), mergeSize = 1;
		while (mergeSize < len) {
			ListNode *preHead1 = &dummy;
			while (preHead1->next){
				ListNode *tail1 = preHead1, *tail2 = preHead1; //tail1 is also the preHead2
				int i = mergeSize;
				while (i-- && tail1->next) {
					tail1 = tail1->next;
					// Move ahead twice if possible
					if (tail2->next) tail2 = tail2->next;
					if (tail2->next) tail2 = tail2->next;
				}
				if (!tail1->next) break; // list 2 doesn't exist, break early

				// Split into different list
				ListNode *head1 = preHead1->next, *head2 = tail1->next, *nextNode = tail2->next;
				preHead1->next = tail1->next = tail2->next = nullptr;
				preHead1->next = mergeList(head1, head2);
				// After merge, connect all lists into one.
				preHead1 = tail1->val <= tail2->val ? tail2 : tail1; // mergeList below is stable. It makes sure for equal items, item in l1 comes first
				preHead1->next = nextNode;
			}
			mergeSize *= 2;
		}
		return dummy.next;;
	}

	// Recursive
    ListNode* sortLinkedList(ListNode *&head, int N) {
        if (N == 0) return NULL;
        if (N == 1) {
            ListNode* cur = head;
            head = head->next;
            cur->next = NULL;
            return cur;
        }
        int half = N / 2;
        ListNode* head1 = sortLinkedList(head, half);
        ListNode* head2 = sortLinkedList(head, N - half);
        return mergeList(head1, head2);
    }
    
    ListNode* mergeList(ListNode *head1, ListNode*head2) {
        ListNode dummy(0); dummy.next = NULL;
        ListNode *cur = &dummy;
        while (head1 && head2)
        {
            ListNode **min = head1->val <= head2->val ? &head1 : &head2;
            cur->next = *min;
            cur = cur->next;
            *min = (*min)->next;
        }
        if (!head1) cur->next = head2;
        if (!head2) cur->next = head1;
        return dummy.next;
    }
    
    int getLength(ListNode *head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }
};