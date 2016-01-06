#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int length = len(head);
        if (length < 2)
            return true;
        ListNode *split, *right, *pivot = NULL;
        split = advance(head, (length >> 1) - 1);
        pivot = right = split->next;
        split->next = NULL;
        if (length % 2) {
            right = right->next;
        }
        right = reverse(right);
        bool ret = equal(head, right);
        right = reverse(right);
        split->next = pivot;
        return ret;
    }
    ListNode *advance(ListNode *head, int x) {
        for (; x; --x)
            head = head->next;
        return head;
    }
    int len(ListNode *head) {
        int ret = 0;
        for (; head; head = head->next)
            ++ret;
        return ret;
    }
    ListNode *reverse(ListNode *head) {
        ListNode dummy(0);
        while (head) {
            ListNode *cur = head;
            head = head->next;
            cur->next = dummy.next;
            dummy.next = cur;
        }
        return dummy.next;
    }
    bool equal(ListNode *lhs, ListNode *rhs) {
        for (; lhs && rhs; lhs = lhs->next, rhs = rhs->next)
            if (lhs->val != rhs->val)
                return false;
        return !lhs && !rhs;
    }
};

int main(void)
{
    return 0;
}
