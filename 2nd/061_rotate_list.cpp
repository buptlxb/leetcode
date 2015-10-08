#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = lengthOf(head);
        if (len < 2)
            return head;
        k %= len;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pos = &dummy;
        for (int i = 0, iend = len-k; i < iend; ++i) {
            pos = pos->next;
        }
        ListNode *tmp = pos;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = dummy.next;
        dummy.next = pos->next;
        pos->next = NULL;
        return dummy.next;
    }
    int lengthOf(ListNode *head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
};

int main(void)
{
    return 0;
} 
