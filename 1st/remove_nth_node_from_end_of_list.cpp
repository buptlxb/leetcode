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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *root = head;
        ListNode *start = head;
        ListNode *prev = NULL;
        while (n > 0) {
            prev = head;
            head = prev->next;
            n--;
        }
        if (!head) {
            return start->next;
        }

        while (head) {
            prev = start;
            start = prev->next;
            head = head->next;
        }
        prev->next = prev->next == NULL ? NULL : prev->next->next;
        return root;
    }
};

void print_list(ListNode *head)
{
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(void)
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);

    a.next = &b;
    b.next = &c;
//    c.next = &d;
//    d.next = &e;
    ListNode *head = Solution().removeNthFromEnd(&a, 1);
    print_list(head);
    return 0;
}
