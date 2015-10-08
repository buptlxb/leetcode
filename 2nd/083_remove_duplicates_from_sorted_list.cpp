#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode *ret = head;
        ListNode *pos = head;
        head = pos->next;
        while (head) {
            if (head->val == pos->val) {
                pos->next = head->next;
                delete head;
            } else {
                pos = pos->next;
            }
            head = pos->next;
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
