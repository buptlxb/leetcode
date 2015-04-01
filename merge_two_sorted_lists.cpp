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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode dummy(-1);
        ListNode *root = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                root->next = l1;
                l1 = l1->next;
            } else {
                root->next = l2;
                l2 = l2->next;
            }
            root = root->next;
        }

        while (l1) {
            root->next = l1;
            l1 = l1->next;
            root = root->next;
        }

        while (l2) {
            root->next = l2;
            l2 = l2->next;
            root = root->next;
        }
        return dummy.next;
    }
};

int main(void)
{
    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(3);
    ListNode a4(4);
    ListNode a5(5);
    a1.next = &a3;
    a3.next = &a5;
    a2.next = &a4;
    ListNode *ret = Solution().mergeTwoLists(&a1, &a2);
    while (ret) {
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}
