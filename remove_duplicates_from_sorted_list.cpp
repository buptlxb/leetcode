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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *ret = head;
        ListNode *index = head;
        ListNode *cur = head->next;
        while (cur) {
            if (index->val != cur->val) {
                index->next = cur;
                index = index->next;
            }
            cur = cur->next;
        }
        index->next = NULL;
        return ret;
    }
};

int main(void)
{
    ListNode a1(1);
    ListNode a2(1);
    ListNode a3(2);
    ListNode a4(3);
    ListNode a5(3);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;

    ListNode *ret = Solution().deleteDuplicates(&a1);
    while (ret) {
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}
