#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        bool isOdd = true;
        ListNode odd(-1), even(-1);
        ListNode *op = &odd, *ep = &even;
        while (head) {
            if (isOdd) {
                op->next = head;
                op = op->next;
            } else {
                ep->next = head;
                ep = ep->next;
            }
            head = head->next;
            isOdd = !isOdd;
        }
        op->next = even.next;
        ep->next = NULL;
        return odd.next;
    }
};

int main(void)
{
    return 0;
}
