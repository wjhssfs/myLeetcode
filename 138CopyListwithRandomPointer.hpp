// 138 Copy List with Random Pointer 
// 
// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
// 
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
		if (!head) return 0;
		unordered_map<RandomListNode *, RandomListNode *> org2New;
		RandomListNode *nHead = new RandomListNode(head->label);
		org2New[head] = nHead;
		RandomListNode * cur = head;
		while (cur){
			if (cur->random){
				if (org2New.find(cur->random) == org2New.end()){
					RandomListNode *newRandom = new RandomListNode(cur->random->label);
					org2New[cur->random] = newRandom;
				}
				org2New[cur]->random = org2New[cur->random];
			}
			if (cur->next){
				if (org2New.find(cur->next) == org2New.end()){
					RandomListNode *newNext = new RandomListNode(cur->next->label);
					org2New[cur->next] = newNext;
				}
				org2New[cur]->next = org2New[cur->next];
			}
			cur = cur->next;
		}

		return nHead;
	}
};

class Solution2 {
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
    
    RandomListNode *copyRandomList_2(RandomListNode *head) {
        if (!head) return NULL;
        unordered_map<RandomListNode *, RandomListNode *> map;
        RandomListNode dummy(0), *curNew = &dummy, *cur = head;
        while (cur) 
        {
            if (map.find(cur) == map.end())
                map[cur] = new RandomListNode(cur->label);
            if (cur->random && map.find(cur->random) == map.end())
                map[cur->random] = new RandomListNode(cur->random->label);
            curNew->next = map[cur];
            curNew = curNew->next;
            curNew->random = map[cur->random];
            cur = cur->next;
        }
        return dummy.next;
    }
};