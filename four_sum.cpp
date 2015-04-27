#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::set;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        set<vector<int> > ret;
        vector<int> tmp;
        for (vector<int>::size_type i = 0, isize = num.size(); i < isize; ++i) {
            for (vector<int>::size_type j = i+1, jsize = isize; j < jsize; ++j) {
                vector<int>::size_type left = j+1, right = jsize-1;
                while (left < right) {
                    int sum = num[i] + num[j] + num[left] + num[right];
                    if (sum == target) {
                        tmp.clear();
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[left]);
                        tmp.push_back(num[right]);
                        ret.insert(tmp);
                        --right;
                        ++left;
                    } else if (sum > target) {
                        --right;
                    } else {
                        ++left;
                    }
                }
            }
        }
        return vector<vector<int> >(ret.begin(), ret.end());
    }
};

int main(void)
{
    int array[] = {1, 0, -1, 0, -2, 2};
    vector<int> num(array, array+sizeof(array)/sizeof(array[0]));
    int target = 0;
    vector<vector<int> > ret = Solution().fourSum(num, target);
    for (vector<vector<int> >::size_type i = 0, isize = ret.size(); i < isize; ++i) {
        for (vector<int>::size_type j = 0, jsize = ret[i].size(); j < jsize; ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
