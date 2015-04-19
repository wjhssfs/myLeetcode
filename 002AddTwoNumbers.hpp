// 2 Add Two Numbers 
// You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *vhead = new ListNode(0);
        ListNode *cur = vhead;
        int carry = 0;
        while(l1 || l2){
            int v = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            if(v > 9){
                v=v%10;
                carry = 1;
            }else{
                carry = 0;
            }
            ListNode *newNode = new ListNode (v);
            cur->next = newNode;
            cur = newNode;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(carry){
            ListNode *newNode1 = new ListNode (1);
            cur->next = newNode1;
        }
        cur = vhead->next;
        delete vhead;
        return cur;
    }
};

class Solution2 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *cur = &dummy;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum >= 10 ? 1 : 0;
            sum %= 10;
            ListNode *newNode = new ListNode(sum);
            cur->next = newNode;
            cur = newNode;
        }
        return dummy.next;
    }
};
