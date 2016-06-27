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
    unsigned int getLength(ListNode *head) {
        int ret = 0;
        while (head) {
            head = head->next;
            ret++;
        }
        return ret;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       int lenA = getLength(headA);
       int lenB = getLength(headB);
       if (lenA  > lenB) {
           int forward = lenA - lenB;
           while (forward) {
               headA = headA->next;
               forward--;
           }
       } else if (lenA < lenB) {
           int forward = lenB - lenA;
           while (forward) {
               headB = headB->next;
               forward--;
           }
       }
       ListNode *node = NULL;
       while (headA && headB) {
           if (headA == headB)
               break;
           headA = headA->next;
           headB = headB->next;
       }
       if (headA)
           node = headA;
       return node;
    }
};

int main(void)
{
    ListNode a1(1);
    ListNode a2(2);
    ListNode b3(3);
    ListNode b4(4);
    ListNode b5(5);
    ListNode c6(6);
    ListNode c7(7);
    ListNode c8(8);
    a1.next = &a2;
    a2.next = &c6;
    b3.next = &b4;
    b4.next = &b5;
    b5.next = &c6;
    c6.next = &c7;
    c7.next = &c8;

    cout << Solution().getIntersectionNode(&a1, &b3)->val << endl;
    return 0;
}
