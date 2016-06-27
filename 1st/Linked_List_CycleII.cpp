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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (fast && fast->next && fast!=slow);
        if (!fast || !fast->next)
            return NULL;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};

int main(void)
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n3;
    ListNode *ret = Solution().detectCycle(&n1);
    if (!ret)
        cout << "no cycyle" << endl;
    else
        cout << ret->val << endl;
    return 0;
}
