#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::const_iterator It;
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ret;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates.begin(), candidates.end(), target, ret, tmp);
        return ret;
    }
    void combinationSum(It start, It end, int target, vector<vector<int> > &ret, vector<int> &tmp) {
        if (target == 0) {
            ret.push_back(tmp);
        } else {
            for (It i = start; i != end; ++i) {
                if (*i <= target) {
                    tmp.push_back(*i);
                    combinationSum(i, end, target-*i, ret, tmp);
                    tmp.pop_back();
                } else
                    break;
            }
        }
    }
};

ostream & operator<< (ostream &os, vector<vector<int> > vec)
{
    os << "[" << endl;
    for (vector<vector<int> >::iterator i = vec.begin(), iend = vec.end(); i != iend; ++i) {
        os << "\t[ ";
        for (vector<int>::iterator j = i->begin(), jend = i->end(); j != jend; ++j) {
            os << *j << " ";
        }
        os << "]" << endl;
    }
    os << "]";
    return os;
}

int main(void)
{
    int array[] = {2, 3, 6, 7};
    vector<int> candidates(array, array+sizeof(array)/sizeof(int));
    int target = 7;
    vector<vector<int> > ret = Solution().combinationSum(candidates, target);
    cout << ret << endl;
    return 0;
}
