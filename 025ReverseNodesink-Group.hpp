// 25 Reverse Nodes in k-Group
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// You may not alter the values in the nodes, only nodes itself may be changed.

// Only constant memory is allowed.

// For example,
// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1) return head;
        ListNode vhead(0);
        vhead.next = head;
        ListNode *p0, *p1, *p2, *p3, *p4, *p5;
        p0 = &vhead;
        while (p0 && p0->next)
        {
            p1 = p0;
            for (int i = 0; i <= k; i++) {
                if (!p1) return vhead.next;
                p1 = p1->next;
            }
            p4 = p1;
            p2 = p5 = p0->next;
            p3 = p2->next;
            while (p2 != p1)
            {
                p2->next = p4;
                p4 = p2;
                p2 = p3;
                if(p3)p3 = p3->next;
            }
            p0->next = p4;
            p0 = p5;
        }

        return vhead.next;
    }
};

class Solution2 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1) return head;
        int reverseTimes = GetLength(head) / k;
        ListNode dummy(0); dummy.next = head;
        ListNode *ins = &dummy, *cur = ins->next;
        while (reverseTimes--) 
        {
            for (int i = 0; i < k - 1; ++i) {
                ListNode *move = cur->next;
                cur->next = move->next;
                move->next = ins->next;
                ins->next = move;
            }
            ins = cur;
            cur = ins->next;
        }
        return dummy.next;
    }

    int GetLength(ListNode *head) {
        int length = 0;
        while (head) {
            head = head->next;
            length++;
        }
        return length;
    }
};