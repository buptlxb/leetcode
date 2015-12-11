#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        while (p->next) {
            if (p->next->val != val)
                p = p->next;
            else
                p->next = p->next->next;
        }
        return dummy.next;
    }
};

int main(void)
{
    return 0;
}
