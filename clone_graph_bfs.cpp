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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;

        queue<UndirectedGraphNode *> q;
        q.push(node);

        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> umap;
        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
        umap[node] = ret;

        while (!q.empty()) {
            UndirectedGraphNode *cur = q.front();
            q.pop();
            for (vector<UndirectedGraphNode *>::size_type i = 0; i < cur->neighbors.size(); i++) {
                unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator iter = umap.find(cur->neighbors[i]);
                if (iter == umap.end()) {
                    q.push(cur->neighbors[i]);
                    UndirectedGraphNode *nbr = new UndirectedGraphNode(cur->neighbors[i]->label);
                    umap[cur->neighbors[i]] = nbr;
                    umap[cur]->neighbors.push_back(nbr);
                } else {
                    umap[cur]->neighbors.push_back(iter->second);
                }
            }
        }
        return ret;   
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
