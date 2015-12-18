#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(-1), *pos = &dummy;
        while (head) {
            ListNode *cur = head;
            head = head->next;
            cur->next = pos->next;
            pos->next = cur;
        }
        return dummy.next;
    }
};

int main(void)
{
    return 0;
}
