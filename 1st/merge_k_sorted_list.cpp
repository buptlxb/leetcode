#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
    bool operator() (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode n(-1);
        ListNode *p = &n;
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        if (lists.empty())
            return NULL;
        for (vector<ListNode *>::size_type i = 0, iend = lists.size(); i < iend; ++i) {
            if (lists[i])
                q.push(lists[i]);
        }
        while (!q.empty()) {
            p->next = q.top();
            p = p->next;
            q.pop();
            if (p->next)
                q.push(p->next);
        }
        return n.next;
    }
};

int main(void)
{
    vector<ListNode *> lists;
    ListNode n0(0);
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    lists.push_back(&n0);
    lists.push_back(&n1);
    lists.push_back(&n2);
    lists.push_back(NULL);
    lists.push_back(NULL);
    lists.push_back(&n3);
    ListNode *head = Solution().mergeKLists(lists);
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}
