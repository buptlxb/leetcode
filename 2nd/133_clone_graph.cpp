#include <iostream>
#include <vector>
#include <map>

using namespace std;


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int, UndirectedGraphNode*> m;
        if (!node)
            return node;
        return cloneGraph(node, m);
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, map<int, UndirectedGraphNode*> &m) {
        UndirectedGraphNode *new_node = getNode(node->label, m);
        for (auto n : node->neighbors) {
            if (!m[n->label]) {
                cloneGraph(n, m);
            }
            new_node->neighbors.push_back(m[n->label]);
        }
        return new_node;
    }
    UndirectedGraphNode *getNode(int label, map<int, UndirectedGraphNode*> &m) {
        if (!m[label])
            m[label] = new UndirectedGraphNode(label);
        return m[label];
    }
};

int main(void)
{
    return 0;
}
