#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    typedef pair<int, int> Point;
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Point> candidates, ret;
        candidates.reserve(buildings.size() << 1);
        for (auto x : buildings) {
            candidates.push_back(Point(x[0], -x[2]));
            candidates.push_back(Point(x[1], x[2]));
        }
        sort(candidates.begin(), candidates.end());
        multiset<int> lines;
        lines.insert(0);
        int cur = 0, prev = 0;
        for (auto c : candidates) {
            if (c.second > 0)
                lines.erase(lines.find(c.second));
            else
                lines.insert(-c.second);
            cur = *lines.rbegin();
            if (cur != prev) {
                ret.push_back(Point(c.first, cur));
                prev = cur;
            }
        }
        return ret;
    }
};

int main(void)
{
    vector<vector<int>> buildings{{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    Solution().getSkyline(buildings);
    return 0;
}
