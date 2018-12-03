// 445. Add Two Numbers II
// You are given two linked lists representing two non-negative numbers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

// Example:

// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        int c = 0;
        while (l1) {s1.push(l1->val); l1 = l1->next;}
        while (l2) {s2.push(l2->val); l2 = l2->next;}
        ListNode vHead(0);
        while (s1.size() || s2.size() || c) {
            int v = (s1.size() ? s1.top() : 0) + 
                (s2.size() ? s2.top() : 0) + c;
            c = v / 10;
            v = v % 10;
            auto nNode = new ListNode(v);
            nNode->next = vHead.next;
            vHead.next = nNode;
            if (s1.size()) s1.pop();
            if (s2.size()) s2.pop();
        }
        return vHead.next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int szl1 = 0, szl2 = 0;
        for (auto t = l1; t; t = t->next) szl1++;
        for (auto t = l2; t; t = t->next) szl2++;
        ListNode *cur = nullptr;
        while (szl1 || szl2) {
            int sum = 0;
            if (szl1 >= szl2) {sum += l1->val; l1 = l1->next; --szl1;}
            if (szl2 > szl1) {sum += l2->val; l2 = l2->next;--szl2;}
            auto t = new ListNode(sum);
            t->next = cur;
            cur = t;
        }
        ListNode *head = nullptr;
        int carry = 0;
        while (cur) {
            cur->val += carry;
            carry = cur->val / 10;
            cur->val = cur->val % 10;
            auto t = cur->next;
            cur->next = head;
            head = cur;
            cur = t;
        }
        if (carry) {
            auto t = new ListNode(carry);
            t->next = head;
            head = t;
        }
        return head;
    }
};
206 Reverse Linked List 