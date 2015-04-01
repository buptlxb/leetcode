#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};

class Solution {
    private :
        int length(ListNode *head) {
            int length = 0;
            while (head) {
                head = head->next;
                ++length;
            }
            return length;
        }
        ListNode *next(ListNode *head, int n) {
            while (n > 0 && head) {
                head = head->next;
                n--;
            }
            return head;
        }
    public :
        void print(ListNode *head) {
            while (head) {
                cout << head->val << " ";
                head = head->next;
            }
            cout << endl;
        }
        ListNode *merge(ListNode *lhead, int lsize, ListNode *rhead, int rsize) {
            if (!lsize) {
                ListNode *ptr = rhead;
                while (rsize > 0 && ptr) {
                    ptr = ptr->next;
                    --rsize;
                }
                if (ptr)
                    ptr->next = NULL;
                return rhead;
            }
            if (!rsize) {
                ListNode *ptr = lhead;
                while (lsize > 0 && ptr) {
                    ptr = ptr->next;
                    --lsize;
                }
                if (ptr)
                    ptr->next = NULL;
                return lhead;
            }

            ListNode *lptr = lhead;
            ListNode *rptr = rhead;
            ListNode *cur = NULL;
            ListNode *head = NULL;
            while (lsize > 0 && rsize > 0) {
                if (lptr->val <= rptr->val) {
                    if (cur) {
                        cur->next = lptr;
                        cur = cur->next;
                    } else {
                        cur = lptr;
                        head = cur;
                    }
                    lptr = lptr->next;
                    --lsize;
                } else {
                    if (cur) {
                        cur->next = rptr;
                        cur = cur->next;
                    } else {
                        cur = rptr;
                        head = cur;
                    }
                    rptr = rptr->next;
                    --rsize;
                }
            }
            if (lsize > 0) {
                cur->next = lptr;
                while (lsize > 1 && lptr) {
                    lptr = lptr->next;
                    --lsize;
                }
                if (lptr)
                    lptr->next = NULL;
            }
            if (rsize > 0) {
                cur->next = rptr;
                while (rsize > 1 && rptr) {
                    rptr = rptr->next;
                    --rsize;
                }
                if (rptr)
                    rptr->next = NULL;
            }
            return head;
        }
        ListNode *sortList(ListNode *head) {
            if (!head)
                return NULL;
            int len = length(head);
            int interval = 1;
            ListNode *left = head;
            while (interval < len) {
                while (left) {
                    int llen = length(low);
                    lsize = interval < llen ? interval : llen;
                    ListNode *right = next(low, lsize);
                    int rlen = length(right);
                    rsize = interval < rlen ? interval : rlen;
                    merge(left, llen, right, rlen);
                    left = right;
                }
                size *= 2;
            }
            return low;
        }
};

int main(void)
{
    Solution s;
    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(3);
    ListNode a4(4);
    ListNode a5(5);

    //1->3->2->5->4
    a1.next = &a3;
    a3.next = &a2;
    a2.next = &a5;
    a5.next = &a4;

    s.print(&a1);
#if 1
    ListNode *head = s.merge(&a1, 2, &a2, 2);
    s.print(head);
    head = s.merge(&a4, 1, NULL, 0);
    s.print(head);
    head = s.merge(&a1, 4, &a4, 1);
    s.print(head);
#endif

#if 0
    ListNode *head = s.sortList(&a1);
    s.print(head);
#endif
    return 0;
}
