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
        ListNode n1(-1), n2(-1);
        ListNode *p1(&n1), *p2(&n2);
        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = NULL;
        p1->next = n2.next;
        return n1.next;
    }
};

int main(void)
{
    ListNode a1(1);
    ListNode a2(4);
    ListNode a3(3);
    ListNode a4(2);
    ListNode a5(5);
    ListNode a6(2);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = &a6;
    ListNode *head = &a1;
    ListNode *ret = Solution().partition(head, 3);
    while (ret) {
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}
