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

public ListNode reverseKGroup(ListNode head, int k) {
    ListNode curr = head;
    int count = 0;
    while (curr != null && count != k) { // find the k+1 node
        curr = curr.next;
        count++;
    }
    if (count == k) { // if k+1 node is found
        curr = reverseKGroup(curr, k); // reverse list with k+1 node as head
        // head - head-pointer to direct part, 
        // curr - head-pointer to reversed part;
        while (count-- > 0) { // reverse current k-group: 
            ListNode tmp = head.next; // tmp - next head in direct part
            head.next = curr; // preappending "direct" head to the reversed list 
            curr = head; // move head of reversed part to a new node
            head = tmp; // move "direct" head to the next node in direct part
        }
        head = curr;
    }
    return head;
}