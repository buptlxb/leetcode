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
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode helper(0);
        helper.next = head;
        ListNode *cur = head;
        while (cur->next) {
            ListNode *prev = &helper;
            while (prev != cur && prev->next->val <= cur->next->val)
                prev = prev->next;
            if (prev != cur) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = prev->next;
                prev->next = tmp;
            } else
                cur = cur->next;
        }
        return helper.next;
    }
};

int main(void)
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    ListNode n7(7);
    ListNode n8(8);
    ListNode n9(9);
    n9.next = &n8;
    n8.next = &n7;
    n7.next = &n6;
    n6.next = &n5;
    n5.next = &n4;
    n4.next = &n3;
    n3.next = &n2;
    n2.next = &n1;
    ListNode *ret = Solution().insertionSortList(&n9);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;
    return 0;
}
