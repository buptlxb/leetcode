#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ret;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, 0, target, tmp, ret);
        return ret;
    }
    void combinationSum(vector<int> &candidates, sz_t start, int target, vector<int> &tmp, vector<vector<int> > &ret) {
        if (target == 0) {
            ret.push_back(tmp);
        } else if (start < candidates.size() && candidates[start] <= target) {
            tmp.push_back(candidates[start]);
            combinationSum(candidates, start+1, target-candidates[start], tmp, ret);
            tmp.pop_back();
            int i = 1;
            while (candidates[start] == candidates[start+i])
                ++i;
            combinationSum(candidates, start+i, target, tmp, ret);
        }
    }
};

int main(void)
{
    int a[] = {10,1,2,7,6,1,5};
    vector<int> candidates(a, a+sizeof(a)/sizeof(int));
    vector<vector<int> > ret = Solution().combinationSum2(candidates, 8);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
