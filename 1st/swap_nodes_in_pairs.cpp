#include <iostream>

using std::cout;
using std::endl;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode helper(0);
        helper.next = head;
        ListNode *first = &helper;
        ListNode *second = first->next;
        do {
            first->next = second->next;
            second->next = second->next->next;
            first->next->next = second;
            first =  first->next->next;
            second = first->next;
        } while(first->next && second->next);
        return helper.next;
    }
};

int main(void)
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    ListNode *ret = Solution().swapPairs(&n1);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;
    return 0;
}
