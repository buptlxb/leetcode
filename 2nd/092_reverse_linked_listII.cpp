#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pos = &dummy;
        n -= m;
        while (--m > 0) {
            pos = pos->next;
        }
        ListNode *start = pos->next;
        ListNode *end = start;
        while (n > 0) {
            end = end->next;
            --n;
        }
        pos->next = end->next;
        end->next = NULL;
        while (start) {
            ListNode *tmp = start;
            start = start->next;
            tmp->next = pos->next;
            pos->next = tmp;
        }
        return dummy.next;                                                                                                                   
    }   
};

int main(void)
{
    return 0;
}
