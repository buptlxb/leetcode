#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::unordered_map;
using std::queue;
using std::vector;


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &umap) {
        if (!node)
            return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator iter = umap.find(node);
        if (iter != umap.end())
            return iter->second;

        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
        umap[node] = ret;

        for (vector<UndirectedGraphNode *>::size_type i = 0; i < node->neighbors.size(); i++) {
            unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator iter = umap.find(node->neighbors[i]);
            if (iter == umap.end()) {
                umap[node]->neighbors.push_back(cloneGraph(node->neighbors[i], umap));
            } else {
                umap[node]->neighbors.push_back(iter->second);
            }
        }
        return ret;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> umap;
        return cloneGraph(node, umap);   
    }
};

int main(void)
{
    UndirectedGraphNode *u0 = new UndirectedGraphNode(-1);
    UndirectedGraphNode *u1 = new UndirectedGraphNode(1);
    UndirectedGraphNode *u2 = new UndirectedGraphNode(2);
    u0->neighbors.push_back(u1);
    u0->neighbors.push_back(u2);
    u1->neighbors.push_back(u2);
    u2->neighbors.push_back(u2);
    UndirectedGraphNode *ret = Solution().cloneGraph(u0);
    cout << ret->label << endl;
    return 0;
}
