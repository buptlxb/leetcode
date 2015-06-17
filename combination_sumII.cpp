#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::const_iterator It;
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ret;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        combinationSum2(candidates.begin(), candidates.end(), target, ret, tmp);
        return ret;
    }
    void combinationSum2(It start, It end, int target, vector<vector<int> > &ret, vector<int> &tmp) {
        if (target == 0) {
            ret.push_back(tmp);
        } else {
            for (It i = start; i != end; ++i) {
                if (*i > target)
                    break;
                else if (i == start || *i != *(i-1)) {
                    tmp.push_back(*i);
                    combinationSum2(i+1, end, target-*i, ret, tmp);
                    tmp.pop_back();
                } 
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
    int array[] = {10,1,2,7,6,1,5};
    vector<int> candidates(array, array+sizeof(array)/sizeof(int));
    int target = 8;
    vector<vector<int> > ret = Solution().combinationSum2(candidates, target);
    cout << ret << endl;
    return 0;
}
