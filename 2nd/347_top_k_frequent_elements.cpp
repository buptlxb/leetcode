#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
    struct Cmp: less<pair<int, int>> {
        bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second < rhs.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> dict;
        for (auto x : nums) {
            ++dict[x];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq(dict.begin(), dict.end());
        vector<int> ret;
        while (k-- > 0) {
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
