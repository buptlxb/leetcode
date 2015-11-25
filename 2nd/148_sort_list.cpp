#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int length = len(head);
        sortList(head, length);
    }
    ListNode *sortList(ListNode *head, int length) {
        if (length < 2)
            return head;
        int llen = length >> 1;
        int rlen = length - llen;
        ListNode *rh = split(head, llen);
        ListNode *lh = sortList(head, llen);
        rh = sortList(rh, rlen);
        return merge(lh, rh);
    }
    int len(ListNode *head) {
        int ret = 0;
        for (; head; head = head->next)
            ++ret;
        return ret;
    }
    ListNode *split(ListNode *head, int len) {
        while (--len)
            head = head->next;
        ListNode *ret = head->next;
        head->next = NULL;
        return ret;
    }
    ListNode *merge(ListNode *lh, ListNode *rh) {
        ListNode dummy(-1), *pos = &dummy;
        ListNode *n;
        while (lh && rh) {
            if (lh->val < rh->val) {
                n = lh;
                lh = lh->next;
            } else {
                n = rh;
                rh = rh->next;
            }
            insert(pos, n);
            pos = pos->next;
        }
        pos->next = lh ? lh : rh;
        return dummy.next;
    }
    void insert(ListNode *pos, ListNode *n) {
        n->next = pos->next;
        pos->next = n;
    }
};

int main(void)
{
    return 0;
}
