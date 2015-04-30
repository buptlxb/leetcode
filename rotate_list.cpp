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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next)
            return head;
        int n = lenof(head);
        k %= n;
        if (!k)
            return head;
        head = reverse(head, 0, n-k-1);
        head = reverse(head, n-k, n-1);
        head = reverse(head, 0, n-1);
        return head;
    }

    ListNode *reverse(ListNode *head, int m, int n) {
        if (!head || !head->next || m == n)
            return head;
        ListNode helper(-1);
        helper.next = head;
        ListNode *pos = &helper;
        int i;
        for (i = 0; i < m; ++i) {
            pos = pos->next;
        }
        ListNode *in = pos->next;
        while (i < n) {
            ListNode *tmp = in->next;
            in->next = tmp->next;
            tmp->next = pos->next;
            pos->next = tmp;
            ++i;
        }
        return helper.next;
    }

    int lenof(ListNode *head) {
        int ret = 0;
        while (head) {
            ++ret;
            head = head->next;
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
    ListNode *ret = Solution().rotateRight(&n1, 2);
    print_list(ret);
    return 0;
}
