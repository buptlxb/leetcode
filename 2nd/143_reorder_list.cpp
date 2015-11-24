#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        int length = len(head);
        if (length < 3)
            return;
       length >>= 1;
       ListNode *another = head;
       while (--length > 0) {
           another = another->next;
       }
       ListNode *tmp = another;
       another = another->next;
       tmp->next = NULL;
       another = reverse(another);
       merge(another, head);
    }
    int len(ListNode *head) {
        int cnt = 0;
        while (head) {
            head = head->next;
            ++cnt;
        }
        return cnt;
    }
    ListNode *reverse(ListNode *head) {
        ListNode dummy(-1);
        ListNode *pos = &dummy;
        while (head) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = pos->next;
            pos->next = tmp;
        }
        return dummy.next;
    }
    void merge(ListNode *src, ListNode *dst) {
        ListNode dummy(-1);
        ListNode *pos = &dummy;
        bool turn = false;
        while (dst && src) {
            ListNode *tmp;
            if (turn) {
                tmp = src;
                src = src->next;
            } else {
                tmp = dst;
                dst = dst->next;
            }
            tmp->next = NULL;
            pos->next = tmp;
            pos = pos->next;
            turn = !turn;
        }
        while (dst) {
            ListNode *tmp = dst;
            dst = dst->next;
            tmp->next = NULL;
            pos->next = tmp;
            pos = pos->next;
        }
        while (src) {
            ListNode *tmp = src;
            src = src->next;
            tmp->next = NULL;
            pos->next = tmp;
            pos = pos->next;
        }
    }
};

int main(void)
{
    return 0;
}
