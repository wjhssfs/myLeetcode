// 430. Flatten a Multilevel Doubly Linked List

// Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

// Example:

// Input:
//  1---2---3---4---5---6--NULL
//          |
//          7---8---9---10--NULL
//              |
//              11--12--NULL

// Output:
// 1-2-3-7-8-11-12-9-10-4-5-6-NULL
// Explanation for the above example:


/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if( head == nullptr) return head;
        Node* p = head; 
        while( p!= nullptr) {
            /* CASE 1: if no child, proceed */
            if( p->child == nullptr ) {
                p = p->next;
                continue;
            }
            /* CASE 2: got child, find the tail of the child and link it to p->next */
            Node* temp = p->child;
            // Find the tail of the child
            while( temp->next != nullptr ) 
                temp = temp->next;
            // Connect tail with p->next, if it is not null
            temp->next = p->next;  
            if( p->next != nullptr )  p->next->prev = temp;
            // Connect p with p->child, and remove p->child
            p->next = p->child; 
            p->child->prev = p;
            p->child = nullptr;
        }
        return head;
    }
};

  public Node flatten(Node head) {
        flattentail(head);
        return head;
    }

    // flattentail: flatten the node "head" and return the tail in its child (if exists)
    // the tail means the last node after flattening "head"

    // Five situations:
    // 1. null - no need to flatten, just return it
    // 2. no child, no next - no need to flatten, it is the last element, just return it
    // 3. no child, next - no need to flatten, go next
    // 4. child, no next - flatten the child and done
    // 5. child, next - flatten the child, connect it with the next, go next

    private Node flattentail(Node head) {
        if (head == null) return head; // CASE 1
        if (head.child == null) {
            if (head.next == null) return head; // CASE 2
            return flattentail(head.next); // CASE 3
        }
        else {
            Node child = head.child;  
            head.child = null;
            Node next = head.next;
            Node childtail = flattentail(child);
            head.next = child;
            child.prev = head;  
                if (next != null) { // CASE 5
                    childtail.next = next;
                    next.prev = childtail;
                    return flattentail(next);
                }
            return childtail; // CASE 4
        }       
    }