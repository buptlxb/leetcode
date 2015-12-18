#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    struct GraphNode {
        set<int>::size_type degree;
        set<int> adjacents;
    };
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ret;
        vector<pair<int, int>> ps;
        sort(prerequisites.begin(), prerequisites.end());
        unique_copy(prerequisites.begin(), prerequisites.end(), back_inserter(ps));
        vector<GraphNode> graph(numCourses);
        for (auto p : ps) {
            ++graph[p.first].degree;
            graph[p.second].adjacents.insert(p.first);
        }
        set<int> courses;
        for (int i = 0; i < numCourses; ++i)
            courses.insert(i);
        bool done = false;
        while (!done && !courses.empty()) {
            done = true;
            for (auto i = courses.begin(), iend = courses.end(); i != iend; ) {
                if (graph[*i].degree == 0) {
                    done = false;
                    for (auto adj : graph[*i].adjacents)
                        --graph[adj].degree;
                    ret.push_back(*i);
                    courses.erase(i++);
                } else 
                    ++i;
            }
        }
        return courses.empty() ? ret : vector<int> ();
    }
};

int main(void)
{
    return 0;
}
