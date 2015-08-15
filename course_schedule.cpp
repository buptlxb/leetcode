#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Node {
    Node () : degree(0) { }
    int degree;
    set<int> children;
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<Node> table(numCourses, Node());
        
        sort(prerequisites.begin(), prerequisites.end());
        prerequisites.erase(unique(prerequisites.begin(), prerequisites.end()), prerequisites.end());
        for (auto p : prerequisites) {
            table[p.first].degree++;
            table[p.second].children.insert(p.first);
        }
        bool flag = true;
        set<int> courses;
        for (int i = 0; i < numCourses; ++i)
            courses.insert(i);
        while (flag && !courses.empty()) {
            flag = false;
            set<int> tmp;
            for (auto c : courses) {
                if (table[c].degree == 0) {
                    flag = true;
                    tmp.insert(c);
                    for (auto x : table[c].children)
                        table[x].degree--;
                }
            }
            for (auto x : tmp) {
                courses.erase(x);
            }
        }
        return courses.empty();
    }
};

int main(void)
{
    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(make_pair(0, 1));
    //prerequisites.push_back(make_pair(1, 0));
    cout << boolalpha << Solution().canFinish(2, prerequisites) << endl;
    return 0;
}
