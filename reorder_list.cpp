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
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next)
            return;
        int length = len(head) >> 1;
        ListNode *tmp = head;
        for (int i = 0; i < length; ++i)
            tmp = tmp->next;
        ListNode *insert = tmp->next;
        tmp->next = NULL;
        insert = reverse(insert);

        while (insert) {
            tmp = insert;
            insert = insert->next;
            tmp->next = head->next;
            head->next = tmp;
            head = head->next->next;
        }
    }
    ListNode * reverse(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode helper(-1);
        while (head) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = helper.next;
            helper.next = tmp;
        }
        return helper.next;
    }
    int len(ListNode *head) {
        int ret = 0;
        while (head) {
            head = head->next;
            ++ret;
        }
        return ret;
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
    ListNode n4(4);
    ListNode n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    Solution().reorderList(&n1);
    print_list(&n1);
    return 0;
}
