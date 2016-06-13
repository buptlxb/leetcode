#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct MyLess : less<pair<int, int>> {
    bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs)
    {   
        return lhs.first < rhs.first || lhs.first == rhs.first && rhs.second < lhs.second;
    }   
};

void print(const vector<pair<int, int>> &envelopes)
{
    for (auto e : envelopes) {
        cout << "[" << e.first << ", " << e.second << "]" << endl;
    }   
}

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), MyLess());
        vector<int> lis;
        for (auto e : envelopes) {
            if (lis.empty() || lis.back() < e.second) {
                lis.push_back(e.second);
            } else {
                *lower_bound(lis.begin(), lis.end(), e.second) = e.second;
            }   
        }   
        return lis.size();
    }   
};

int main(void)
{
    //vector<pair<int, int>> envelopes{{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    vector<pair<int, int>> envelopes{{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
    Solution s;
    cout << s.maxEnvelopes(envelopes) << endl;
    return 0;
}
