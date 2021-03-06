// 143 Reorder List 
// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// You must do this in-place without altering the nodes' values.
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// O(N) time, O(1) space in total
void reorderList(ListNode *head) {
    if (!head || !head->next) return;

    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;

    p2 = head2->next;
    head2->next = NULL;
    while (p2) {
        p1 = p2->next;
        p2->next = head2;
        head2 = p2;
        p2 = p1;
    }

    // merge two lists: O(n)
    for (p1 = head, p2 = head2; p1; ) {
        auto t = p1->next;
        p1 = p1->next = p2;
        p2 = t;
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void reorderList(ListNode* head, int len, ListNode*& tail) {
        if (len == 1) {
            tail = head->next;
            head->next = nullptr;
        } else if (len == 2) {
            tail = head->next->next;
            head->next->next = nullptr;
        } else {
            reorderList(head->next, len - 2, tail);
            auto t = head->next;
            head->next = tail;
            tail = tail->next;
            head->next->next = t;
        }
    }
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        auto t = head;
        int len = 0;
        while (t) {++len; t = t->next;}
        ListNode* tail = nullptr;
        reorderList(head, len, tail);
    }
};