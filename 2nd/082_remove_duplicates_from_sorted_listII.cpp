#include <iostream>
#include <vector>

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
        ListNode dummy(-1);
        ListNode *pos = &dummy;
        ListNode *cur = head;
        bool isDuplicated = false;
        head = head->next;
        while (head) {
            if (head->val == cur->val) {
                ListNode *tmp = head;
                head = head->next;
                isDuplicated = true;
                delete tmp;
            } else {
                if (!isDuplicated) {
                    pos->next = cur;
                    pos = pos->next;
                    cur = head;
                } else {
                    delete cur;
                    cur = head;
                    isDuplicated = false;
                }
                head = head->next;
            }
        }
        if (!isDuplicated) {
            pos->next = cur;
            pos = pos->next;
        } else {
            delete cur;
        }
        pos->next = NULL;
        return dummy.next;
    }
};

int main(void)
{
    return 0;
}
