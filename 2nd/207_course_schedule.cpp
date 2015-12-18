#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    struct Course {
        int degree;
        set<int> children;
    };
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<pair<int, int> > ps;
        sort(prerequisites.begin(), prerequisites.end());
        unique_copy(prerequisites.begin(), prerequisites.end(), back_inserter(ps));
        vector<Course> graph(numCourses);
        for (auto p : ps) {
            ++graph[p.first].degree;
            graph[p.second].children.insert(p.first);
        }
        bool done = false;
        set<int> courses;
        for (int i = 0; i < numCourses; ++i)
            courses.insert(i);
        while (!done && !courses.empty()) {
            done = true;
            for (auto i = courses.begin(), iend = courses.end(); i != iend; ) {
                if (graph[*i].degree == 0) {
                    done = false;
                    for (auto x : graph[*i].children)
                        --graph[x].degree;
                    courses.erase(i++);
                } else
                    ++i;
            }
        }
        return courses.empty();
    }
};

int main(void)
{
    return 0;
}
