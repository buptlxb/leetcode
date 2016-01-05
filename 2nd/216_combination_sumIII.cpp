#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> tmp;
        combinationSum3(k, n, tmp, ret);
        return ret;
    }   
    void combinationSum3(int k, int n, vector<int> &tmp, vector<vector<int>> &ret) {
        if (k == 0) {
            if (n == 0)
                ret.push_back(tmp);
            return;
        }   
        int start = tmp.empty() ? 0 : tmp.back();
        for (int i = start+1; i < 10; ++i) {
            if (i <= n) {
                tmp.push_back(i);
                combinationSum3(k-1, n-i, tmp, ret);
                tmp.pop_back();
            }   
        }   
    }   
};

int main(void)
{
    return 0;
}
