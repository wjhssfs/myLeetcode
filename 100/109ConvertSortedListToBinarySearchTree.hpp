// 109 Convert Sorted List to Binary Search Tree 
// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return nullptr;
        ListNode *pivot, *second;
        split(head, pivot, second);
        TreeNode *cur = new TreeNode(pivot->val);
        TreeNode *left = sortedListToBST(head);
        TreeNode *right = sortedListToBST(second);
        cur->left = left;
        cur->right = right;
        return cur;
    }

private:
    void split(ListNode *&head, ListNode *&pivot, ListNode *&second)
    {
        if (!head)
        {
            pivot = second = nullptr; return;
        }
        ListNode *p0 = nullptr, *p1 = head, *p2 = head->next;
        while (p2)
        {
            p0 = p1;
            p1 = p1->next;
            p2 = p2->next;
            if (p2) p2 = p2->next;
        }
        if(p0) p0->next = nullptr;
        else head = nullptr;
        pivot = p1;
        second = p1->next;
    }
};

class Solution2 {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBSTRe(head, getLength(head));
    }
    
    TreeNode *sortedListToBSTRe(ListNode *&head, int length)
    {
        if (length == 0) return NULL;
        int mid = length / 2;
        TreeNode *left = sortedListToBSTRe(head, mid);
        TreeNode *root = new TreeNode(head->val);
        TreeNode *right = sortedListToBSTRe(head->next, length - mid - 1);
        root->left = left;
        root->right = right;
        head = head->next; // this will move head to next
        return root;
    }
    
    int getLength(ListNode *head)
    {
        int length = 0;
        while (head)
        {
            length++;
            head = head->next;
        }
        return length;
    }
};

class Solution {
public:
    ListNode *list;
    int count(ListNode *node){
        int size = 0;
        while (node) {
            ++size;
            node = node->next;
        }
        return size;
    }

    TreeNode *generate(int n){
        if (n == 0)
            return NULL;
        TreeNode *node = new TreeNode(0);
        node->left = generate(n / 2);
        node->val = list->val;
        list = list->next;
        node->right = generate(n - n / 2 - 1);
        return node;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        this->list = head;
        return generate(count(head));
    }
};