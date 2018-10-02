// 708. Insert into a Cyclic Sorted List

// Given a node from a cyclic linked list which is sorted in ascending order, write a function to insert a value into the list such that it remains a cyclic sorted list. The given node can be a reference to any single node in the list, and may not be necessarily the smallest value in the cyclic list.

// If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, the cyclic list should remain sorted.

// If the list is empty (i.e., given node is null), you should create a new single cyclic list and return the reference to that single node. Otherwise, you should return the original given node.

// The following example may help you understand the problem better:


// In the figure above, there is a cyclic sorted list of three elements. You are given a reference to the node with value 3, and we need to insert 2 into the list.


// The new node should insert between node 1 and node 3. After the insertion, the list should look like this, and we should still return node 3.
 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal, nullptr);
            head->next = head;
        }
        else {
            auto cur = head;
            bool inserted = false;
            while (!inserted) {
                if (cur->val == insertVal ||
                    (cur->val < insertVal && cur->next->val > insertVal) ||
                    (cur->val > insertVal && cur->next->val > insertVal && cur->val > cur->next->val) ||
                   (cur->val < insertVal && cur->next->val < insertVal && cur->val > cur->next->val)) {
                    auto p = new Node(insertVal, nullptr);
                    p->next = cur->next;
                    cur->next = p;
                    inserted = true;
                }
                cur = cur->next;
                if (cur == head) break;
            }
            if (!inserted) {
                auto p = new Node(insertVal, nullptr);
                p->next = head->next;
                head->next = p;
            }
        }
        return head;
    }
};

// https://leetcode.com/problems/insert-into-a-cyclic-sorted-list/discuss/149374/Java-5ms-One-Pass-and-Two-Pass-Traverse-With-Detailed-Comments-and-Edge-cases!
class Solution {
    public Node insert(Node start, int x) {
        // if start is null, create a node pointing to itself and return
        if (start == null) {
            Node node = new Node(x, null);
            node.next = node;
            return node;
        }
        // is start is NOT null, try to insert it into correct position
        Node cur = start;
        while (true) {
            // case 1A: has a tipping point, still climbing
            if (cur.val < cur.next.val) { 
                if (cur.val <= x && x <= cur.next.val) { // x in between cur and next
                    insertAfter(cur, x);
                    break;
                }
            // case 1B: has a tipping point, about to return back to min node
            } else if (cur.val > cur.next.val) { 
                if (cur.val <= x || x <= cur.next.val) { // cur is the tipping point, x is max or min val
                    insertAfter(cur, x);
                    break;
                }
            // case 2: NO tipping point, all flat
            } else {
                if (cur.next == start) {  // insert x before we traverse all nodes back to start
                    insertAfter(cur, x);
                    break;
                }
            }
            // None of the above three cases met, go to next node
            cur = cur.next;
        }
        return start;
    }
    
    // insert value x after Node cur
    private void insertAfter(Node cur, int x) {
        cur.next = new Node(x, cur.next);
    }
}