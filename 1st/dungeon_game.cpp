#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        if (dungeon.empty())
            return 0;
        vector<vector<int> > low(dungeon.size(), vector<int>(dungeon.front().size(), 1));
        for (s_t i =  low.size(); i > 0; --i) {
            for (s_t j = low[i-1].size(); j > 0; --j) {
                if (i < low.size() && j < low[i-1].size()) {
                    low[i-1][j-1] = min(max(low[i-1][j]-dungeon[i-1][j-1], 1), max(low[i][j-1]-dungeon[i-1][j-1], 1));
                } else if (i < low.size()) {
                    low[i-1][j-1] = max(low[i][j-1]-dungeon[i-1][j-1], 1);
                } else if (j < low[i-1].size()) {
                    low[i-1][j-1] = max(low[i-1][j]-dungeon[i-1][j-1], 1);
                } else {
                    low[i-1][j-1] = max(low[i-1][j-1]-dungeon[i-1][j-1], 1);
                }
            }
        }
        return low[0][0];
    }
};

int main(void)
{
    int a1[] = {-2, -3, 3};
    int a2[] = {-5, -10, 1};
    int a3[] = {10, 30, -5};
    vector<int> v1(a1, a1+sizeof(a1)/sizeof(int));
    vector<int> v2(a2, a2+sizeof(a2)/sizeof(int));
    vector<int> v3(a3, a3+sizeof(a3)/sizeof(int));
    vector<vector<int> > dungeon;
    dungeon.push_back(v1);
    dungeon.push_back(v2);
    dungeon.push_back(v3);
    cout << Solution().calculateMinimumHP(dungeon) << endl;
    return 0;
}
