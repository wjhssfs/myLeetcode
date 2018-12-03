// 138 Copy List with Random Pointer 
// A linked list is given such that each node contains an additional random pointer which
// could point to any node in the list or null.
// Return a deep copy of the list.

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        return copyRandomList_1(head);
    }
    
    RandomListNode *copyRandomList_1(RandomListNode *head) {
        for (RandomListNode *cur = head; cur; cur = cur->next->next) {
            RandomListNode *newNode = new RandomListNode(cur->label);
            newNode->next = cur->next;
            cur->next = newNode;
        }
        
        for (RandomListNode *cur = head; cur; cur = cur->next->next)
            if (cur->random)
                cur->next->random = cur->random->next;
        
        RandomListNode dummy(0), *curNew = &dummy;
        for (RandomListNode *cur = head; cur; cur = cur->next) {
            curNew->next = cur->next;
            curNew = curNew->next;
            cur->next = cur->next->next;
        }
        return dummy.next;
    }
    
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> mapping;
        auto cur = head;
        while (cur) {
            if (mapping.count(cur) == 0) mapping[cur] = new RandomListNode(cur->label);
            if (cur->next && mapping.count(cur->next) == 0) mapping[cur->next] = new RandomListNode(cur->next->label);
            if (cur->random && mapping.count(cur->random) == 0) mapping[cur->random] = new RandomListNode(cur->random->label);
            mapping[cur]->random = mapping[cur->random];
            mapping[cur]->next = mapping[cur->next];
            cur = cur->next;
        }
        return mapping[head];
    }
};