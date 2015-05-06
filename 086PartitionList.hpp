// 86 Partition List 
// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// 
// You should preserve the original relative order of the nodes in each of the two partitions.
// 
// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *sh, *st, *egh, *egt;
        sh = st = egh = egt = nullptr;
        while (head)
        {
            ListNode *next = head->next;
            head->next = nullptr;
            if (head->val < x)
            {
                if (!sh){
                    sh = st = head;
                }
                else{
                    st->next = head;
                    st = head;
                }
            }else{
                if (!egh){
                    egh = egt = head;
                }
                else
                {
                    egt->next = head;
                    egt = head;
                }
            }
            head = next;
        }
        if (st){
            st->next = egh;
            return sh;
        }
        else{
            return egh;
        }
    }
};

class Solution2 {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy(0), *ins = &dummy, *cur = &dummy;
        dummy.next = head;
        while (cur->next) 
        {
            if (cur->next->val >= x)
            {
                cur = cur->next;
            } 
            else 
            {
                if (cur == ins) 
                {
                    cur = cur->next;
                    ins = ins->next;
                } 
                else 
                {
                    ListNode *move = cur->next;
                    cur->next = move->next;
                    move->next = ins->next;
                    ins->next = move;
                    ins = move;
                }
            }
        }
        return dummy.next;
    }
};