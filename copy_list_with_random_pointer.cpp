#include <iostream>
#include <map>

using namespace std;


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
    typedef map<RandomListNode *, RandomListNode *> RandomListNodeMap;
    typedef RandomListNodeMap::iterator RandomListNodeMapIter;
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNodeMap m;
        return copyRandomList(head, m);
    }
    RandomListNode *copyRandomList(RandomListNode *head, RandomListNodeMap &m) {
        if (!head)
            return head;
        RandomListNode *n = copyRandomListNode(head, m);
        n->random = copyRandomListNode(head->random, m);
        if (n->next == NULL)
            n->next = copyRandomList(head->next, m);
        return n;
    }
    RandomListNode *copyRandomListNode(RandomListNode *head, RandomListNodeMap &m) {
        if (!head)
            return NULL;
        RandomListNodeMapIter found = m.find(head);
        RandomListNode *n;
        if (found != m.end()) {
            n = found->second;
        } else {
            n = new RandomListNode(head->label);
            m[head] = n;
        }
        return n;
    }
};

int main(void)
{
    RandomListNode n1(1);
    RandomListNode n2(2);
    RandomListNode n3(3);
    RandomListNode n4(4);
    RandomListNode n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n1.random = &n3;
    n3.random = &n1;
    RandomListNode *ret = Solution().copyRandomList(&n1);
    while (ret) {
        cout << "label:" << ret->label << " random:";
        if (ret->random)
            cout << ret->random->label;
        else
            cout << "NULL";
        cout << endl;
        ret = ret->next;
    }
}
