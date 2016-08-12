#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *head;
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* h) : head(h) {
        srandom(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *tmp = head, *res;
        for (int k = 1; tmp; tmp = tmp->next, ++k) {
            if (random() % k == 0)
                res = tmp;
        }
        return res->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main(void)
{
    return 0;
}
