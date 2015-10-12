#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return head;
        ListNode left(-1), right(-1);
        ListNode *lp = &left, *rp = &right;
        while (head) {
            if (head->val < x) {
                lp->next = head;
                lp = lp->next;
            } else {
                rp->next = head;
                rp = rp->next;
            }
            head = head->next;
        }
        lp->next = right.next;
        rp->next = NULL;
        return left.next;
    }
};

int main(void)
{
    return 0;
}
