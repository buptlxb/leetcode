#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> m;
        return copyRandomList(head, m);
    }
    RandomListNode *copyRandomList(RandomListNode *head, unordered_map<RandomListNode *, RandomListNode *> &m) {
        if (!head)
            return NULL;
        if (!m[head])
            m[head] = new RandomListNode(head->label);
        if (head->random) {
            if (!m[head->random])
                m[head->random] = new RandomListNode(head->random->label);
            m[head]->random = m[head->random];
        }
        m[head]->next = copyRandomList(head->next, m);
        return m[head];
    }
};

int main(void)
{
    return 0;
}
