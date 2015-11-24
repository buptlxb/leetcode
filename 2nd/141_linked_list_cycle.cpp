#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;
        ListNode *fast = head->next->next;
        while (fast && fast->next) {
            if (fast == head)
                return true;
            head = head->next;
            fast = fast->next->next;
        }
        return false;
    }
};

int main(void)
{
    return 0;
}
