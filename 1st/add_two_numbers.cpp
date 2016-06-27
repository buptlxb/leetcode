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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode helper(-1);
        ListNode *prev = &helper;
        int carry = 0;
        while (l1 && l2) {
            int tmp = l1->val + l2->val + carry;
            carry = tmp / 10;
            prev->next = new ListNode(tmp%10);
            prev = prev->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int tmp = l1->val + carry;
            carry = tmp / 10;
            prev->next = new ListNode(tmp%10);
            prev = prev->next;
            l1 = l1->next;
        }
        while (l2) {
            int tmp = l2->val + carry;
            carry = tmp / 10;
            prev->next = new ListNode(tmp%10);
            prev = prev->next;
            l2 = l2->next;
        }
        if (carry)
            prev->next = new ListNode(carry);
        return helper.next;
    }
};

void print_list(ListNode *head)
{
    if (!head)
        return;
    cout << head->val;
    head = head->next;
    while (head) {
        cout << "->" << head->val;
        head = head->next;
    }
    cout << endl;
}

int main(void)
{
    ListNode n1(2);
    ListNode n2(4);
    ListNode n3(3);
    n1.next = &n2;
    n2.next = &n3;

    ListNode n4(5);
    ListNode n5(6);
    ListNode n6(4);
    n4.next = &n5;
    n5.next = &n6;

    ListNode *ret = Solution().addTwoNumbers(&n1, &n4);
    print_list(&n1);
    print_list(&n4);
    print_list(ret);
    return 0;
}
