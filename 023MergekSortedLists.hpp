// 23 Merge k Sorted Lists 

// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<pair<ListNode *, int>, vector<pair<ListNode *, int>>, myComp> pq;
        ListNode *head = nullptr, *tail = nullptr;
        size_t lastPop = 0;
        for (size_t i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                ListNode *cur = lists[i];
                lists[i] = cur->next;
                cur->next = nullptr;
                pq.push(make_pair(cur, i));
            }
        }
        
        while (!pq.empty()) {
            if (!head) {
                head = tail = pq.top().first;
            }
            else {
                tail->next = pq.top().first;
                tail = tail->next;
            }
            lastPop = pq.top().second;
            pq.pop();

            ListNode *cur = lists[lastPop];
            while (cur && !pq.empty() && cur->val < pq.top().first->val) {
                tail->next = cur;
                tail = cur;
                lists[lastPop] = cur->next;
                cur = cur->next;
                tail->next = nullptr;
            }
            if (cur) {
                pq.push(make_pair(cur, lastPop));
                lists[lastPop] = cur->next;
            }
        }
        return head;
    }
private:
    struct myComp{
        bool operator()(const pair<ListNode *, int> &a, const pair<ListNode *, int> &b)
        {
            return a.first->val > b.first->val;
        }
    };
};

class Mycompare {
public:
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution2 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, Mycompare> q;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i])
                q.push(lists[i]);
        
        ListNode dummy(0), *cur = &dummy;
        while (!q.empty()) {
            ListNode *node = q.top();
            q.pop();
            cur = cur->next = node;
            if (node->next)
                q.push(node->next);
        }
        return dummy.next;
    }
};
