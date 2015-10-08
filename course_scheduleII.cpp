#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> ret;
        vector<int> degrees(numCourses, 0);
        vector<set<int> > children(numCourses, set<int>());
        sort(prerequisites.begin(), prerequisites.end());
        prerequisites.erase(unique(prerequisites.begin(), prerequisites.end()), prerequisites.end());
        for (vector<pair<int, int> >::iterator i = prerequisites.begin(), iend = prerequisites.end(); i != iend; ++i) {
            degrees[i->first] += 1;
            children[i->second].insert(i->first);
        }
        bool flag = true;
        set<int> s;
        for (int i = 0; i < numCourses; ++i) {
            s.insert(i);
        }
        while (flag && !s.empty()) {
            flag = false;
            set<int> tmp;
            for (auto i : s) {
                if (!degrees[i]) {
                    for (auto x : children[i])
                        --degrees[x];
                    tmp.insert(i);
                    flag = true;
                }
            }
            for (auto x : tmp) {
                ret.push_back(x);
                s.erase(x);
            }
        }
        if (s.empty())
            return ret;
        else
            return vector<int> ();
    }
};

int main(void)
{
    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 0));
    prerequisites.push_back(make_pair(3, 1));
    prerequisites.push_back(make_pair(3, 2));
    vector<int> ret = Solution().findOrder(4, prerequisites);
    copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    return 0;
}
