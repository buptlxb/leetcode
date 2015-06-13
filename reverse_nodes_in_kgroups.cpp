#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode *head) {
        ListNode n(-1);
        while (head) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = n.next;
            n.next = tmp;
        }
        return n.next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int i = 1;
        ListNode n(-1);
        ListNode *h = head;
        ListNode *p = &n;
        while (head) {
            if (i % k == 0) {
                ListNode *tmp = head->next;
                head->next = NULL;
                p->next = reverseKGroup(h);
                p = h;
                h = tmp;
                head = tmp;
                ++i;
            } else {
                head = head->next;
                ++i;
            }
        }
        p->next = h;
        return n.next;
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
//    print_list(Solution().reverseKGroup(&n1));
    print_list(Solution().reverseKGroup(&n1, 3));
    return 0;
}
