#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        void print(ListNode *head) {
            while (head) {
                cout << head->val << " ";
                head = head->next;
            }
            cout << endl;
        }
        ListNode *sortList(ListNode *head) {
            if (head == NULL) {
                return NULL;
            }
            int interval = 1;
            ListNode* p = head;
            ListNode* q = NULL;
            ListNode* e = NULL;
            while (true) {
                p = head;
                ListNode* cur = NULL;
                int merge_count = 0;
                while (p) {
                    merge_count++;
                    q = p;
                    int psize = 0;
                    for (int i = 0; i < interval; ++i) {
                        if (q) {
                            ++psize;
                            q = q->next;
                        } else {
                            break;
                        }
                    }
                    // merge two list
                    int qsize = interval;
                    while (psize > 0 || (qsize > 0 && q)) {
                        if (psize == 0) {
                            e = q;
                            q = q->next;
                            --qsize;
                        } else if (qsize == 0 || !q) {
                            e = p;
                            p = p->next;
                            --psize;
                        } else if (p->val <= q->val) {
                            e = p;
                            p = p->next;
                            --psize;
                        } else {
                            e = q;
                            q = q->next;
                            --qsize;
                        }
                        if (cur) {
                            cur->next = e;
                        } else {
                            head = e;
                        }
                        cur = e;
                    }
                    p = q;
                }
                cur->next = NULL;
                if (merge_count <= 1) {
                    return head;
                }
                interval *= 2;
            }
            return NULL;
        }
};

int main(void) {
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

    ListNode *head = s.sortList(&a1);
    s.print(head);
    return 0;
}
