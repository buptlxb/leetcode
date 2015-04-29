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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode helper(-1);
        helper.next = head;
        ListNode *unique = &helper;
        ListNode *p = head;
        bool del = false;
        while (p && p->next) {
            if (p->val == p->next->val) {
                // delete the first duplicate
                unique->next = p->next;
                del = true;
            } else if (del) {
                // delete the last duplicate
                unique->next = p->next;
                del = false;
            } else {
                // found an unique 
                unique = unique->next;
                del = false;
            }
            p = p->next;
        }
        if (p && del)   //remove the last duplicate
            unique->next = p->next;
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
    ListNode n3(3);
    ListNode n4(3);
    ListNode n5(4);
    ListNode n6(4);
    ListNode n7(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    ListNode *ret = Solution().deleteDuplicates(&n1);
    print_list(ret);
    ListNode n11(1);
    ListNode n12(1);
    ListNode n13(1);
    ListNode n14(2);
    ListNode n15(3);
    n11.next = &n12;
    n12.next = &n13;
    n13.next = &n14;
    n14.next = &n15;
    ret = Solution().deleteDuplicates(&n11);
    print_list(ret);
    return 0;
}
