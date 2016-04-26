// 206 Reverse Linked List 
// Reverse a singly linked list.
// Hint:
// A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        while(head){
            ListNode *moveNode = head;
            head = head->next;
            moveNode->next = dummy.next;
            dummy.next = moveNode;
        }
        return dummy.next;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode *newHead = head;
        reReverseList(head, &newHead)->next = nullptr;
        return newHead;
    }
    ListNode *reReverseList(ListNode *cur, ListNode **newHead){
        if(!cur->next) *newHead = cur;
        else reReverseList(cur->next, newHead)->next = cur;
        return cur;
    }
};