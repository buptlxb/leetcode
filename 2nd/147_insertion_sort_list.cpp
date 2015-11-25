#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *sorted = head;
        ListNode *pos, *cur;
        do {
            cur = sorted->next;
            pos = &dummy;
            while (pos != sorted && pos->next->val < cur->val)
                pos = pos->next;
            if (pos == sorted)
                sorted = sorted->next;
            else {
                sorted->next = cur->next;
                cur->next = pos->next;
                pos->next = cur;
            }
        } while (sorted->next);
        return dummy.next;
    }
};

int main(void)
{
    return 0;
}
