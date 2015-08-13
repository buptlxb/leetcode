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
        if (!head)
            return NULL;
        RandomListNode *cur = head;
        while (cur) {
            RandomListNode *n = new RandomListNode(cur->label);
            n->next = cur->next;
            cur->next = n;
            cur = cur->next->next;
        }
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        RandomListNode *p1(head), *p2(head->next), *ret(head->next);
        while (p1) {
            if (p1->next)
                p1->next = p1->next->next;
            if (p2->next)
                p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        return ret;
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
