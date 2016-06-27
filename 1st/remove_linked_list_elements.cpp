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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return NULL;
        ListNode helper(-1);
        helper.next = head;
        ListNode *tmp;
        head = &helper;
        while (head->next) {
            if (head->next->val == val) {
                head->next = head->next->next;
            } else
                head = head->next;
        }
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
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(6);
    ListNode n4(3);
    ListNode n5(4);
    ListNode n6(5);
    ListNode n7(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    print_list(Solution().removeElements(&n1, 6));
    return 0;
}
