#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int, int> > candidates, ret;
        for (auto b : buildings) {
            candidates.push_back(make_pair(b[0], -b[2]));
            candidates.push_back(make_pair(b[1], b[2]));
        }
        sort(candidates.begin(), candidates.end());
        multiset<int> heap;
        int cur(0), prev(0);
        heap.insert(0);
        for (auto c : candidates) {
            if (c.second > 0)
                heap.erase(heap.find(c.second));
            else
                heap.insert(-c.second);
            cur = *heap.rbegin();
            if (cur != prev) {
                ret.push_back(make_pair(c.first, cur));
                prev = cur;
            }
        }
        return ret;
    }
};

int main(void)
{
    int a[][3] = { {2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8} };
    vector<vector<int> > buildings;
    for (int i = 0; i < 5; ++i) {
        buildings.push_back(vector<int>(a[i], a[i]+3));
    }
    vector<pair<int, int> > ret = Solution().getSkyline(buildings);
    for (auto p : ret) {
        cout << "[" << p.first << ", " << p.second << "]" << endl;
    }
    return 0;
}
