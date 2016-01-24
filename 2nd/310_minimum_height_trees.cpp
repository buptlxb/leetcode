#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret;
        if (n == 0)
            return ret;
        if (n == 1) {
            ret.push_back(0);
            return ret;
        }
        vector<set<int>> graph(n);
        for (auto e : edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        vector<int> leaves;
        for (sz_t i = 0; i < n; ++i) {
            if (graph[i].size() == 1)
                leaves.push_back(i);
        }
        while (true) {
            vector<int> next;
            for (auto l : leaves)
                for (auto n : graph[l]) {
                    graph[n].erase(l);
                    if (graph[n].size() == 1)
                        next.push_back(n);
                }
            if (next.empty())
                return leaves;
            leaves.swap(next);
        }
    }
};

int main(void)
{
    //vector<pair<int, int>> edges{{1,0}, {1,2}, {1,3}};
    vector<pair<int, int>> edges{{0,3}, {1,3}, {2,3}, {4,3}, {5,4}};
    Solution s;
    vector<int> ret = s.findMinHeightTrees(6, edges);
    for (auto x : ret)
        cout << x << endl;
    return 0;
}
