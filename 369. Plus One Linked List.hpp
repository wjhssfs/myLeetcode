// 369. Plus One Linked List
// Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

// You may assume the integer do not contain any leading zero, except the number 0 itself.

// The digits are stored such that the most significant digit is at the head of the list.

// Example:
// Input:
// 1->2->3

// Output:
// 1->2->4

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
    ListNode* plusOne(ListNode* head) {
        if (DFShasCarry(head)) {
            auto newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
    bool DFShasCarry(ListNode* head) {
        if (!head) return true;
        if (!DFShasCarry(head->next)) return false;
        if (head->val != 9) {
            ++head->val;
            return false;
        } else {
            head->val = 0;
            return true;
        }
    }
};

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* vHead = new ListNode(0), *start = vHead, *end = vHead;
        vHead->next = head;
        while (end->next) {
            if (end->val != 9) start = end;
            end = end->next;
        }
        if (end->val != 9) {
            ++end->val;
        } else {
            ++start->val;
            start = start->next;
            while (start) {
                start->val = 0;
                start = start->next;
            }
        }
        if (vHead->val) {
            return vHead;
        } else {
            delete vHead;
            return head;
        }
    }
};