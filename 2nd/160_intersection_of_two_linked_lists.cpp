#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        ListNode *pos = headA;
        while (pos->next) {
            pos = pos->next;
        }
        pos->next = headB;
        ListNode *fast = headA, *slow = headA;
        do {
            fast = fast->next->next;
            slow = slow->next;
        } while (fast && fast->next && fast != slow);
        if (fast != slow) {
            prev->next = NULL;
            return NULL;
        }
        slow = headA;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        pos->next = NULL;
        return slow;
    }
};

int main(void)
{
    return 0;
}
