#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct Pair {
        int idx1, idx2;
        long long sum;
        Pair (int a, int b, int c) : idx1(a), idx2(b), sum(c) {}
    };
    struct PairCmp : less<Pair> {
        bool operator() (const Pair &lhs, const Pair &rhs) {
            return lhs.sum > rhs.sum;
        }
    };
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ret;
        ret.reserve(k);
        if (nums1.empty() || nums2.empty())
            return ret;
        priority_queue<Pair, vector<Pair>, PairCmp> pq;
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            pq.push(Pair(i, 0, nums1[i]+nums2[0]));
        }
        while (!pq.empty() && k-- > 0) {
            Pair p = pq.top();
            ret.push_back(make_pair(nums1[p.idx1], nums2[p.idx2]));
            pq.pop();
            if (p.idx2 + 1 <  nums2.size()) {
                p.idx2 += 1;
                p.sum = nums1[p.idx1] + nums2[p.idx2];
                pq.push(p);
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums1{1, 7, 11}, nums2{2, 4, 6};
    int k = 3;
    for (auto p : s.kSmallestPairs(nums1, nums2, k))
        cout << p.first << ", " << p.second << endl;
    return 0;
}
