#include <iostream>

using namespace std;

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
        ListNode *fast = head;
        ListNode *slow = head;
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (fast && fast->next && fast != slow);
        if (!fast || !fast->next)
            return NULL;
        slow = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
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
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n1;
    ListNode *ret = Solution().detectCycle(&n1);
    return 0;
}
