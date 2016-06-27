#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void swap(int &x, int &y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    int is_need_swap(vector<int> &num, int start, int end) {
        for (int i = start; i < end; i++)
            if (num[i] == num[end])
                return false;
        return true;
    }

    void permute(vector<vector<int> > &ret, vector<int> &num, int index) {
        if (index == num.size()-1)
            ret.push_back(vector<int>(num));
        else {
            for (int i = index; i < num.size(); i++) {
                if (is_need_swap(num, index, i)) {
                    swap(num[index], num[i]);
                    permute(ret, num, index+1);
                    swap(num[index], num[i]);
                }
            }
        }

    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ret;
        permute(ret, num, 0);
        return ret;
    }
};

int main(void)
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vector<vector<int> > ret = Solution().permuteUnique(vec);
    for (vector<vector<int> >::iterator iter = ret.begin(); iter != ret.end(); iter++) {
        for (vector<int>::iterator in_iter = iter->begin(); in_iter != iter->end(); in_iter++) {
            cout << *in_iter << ", ";
        }
        cout << endl;
    }
}
