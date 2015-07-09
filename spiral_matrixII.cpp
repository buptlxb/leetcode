#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> tmp(n, 0);
        vector<vector<int> > ret(n, tmp);
        generateMatrix(0, 1, ret);
        return ret;
    }
    void generateMatrix(int order, int x, vector<vector<int> > &ret) {
        vector<vector<int> >::size_type size = ret.size() - order * 2;
        if (size == 0)
            return;
        else if (size == 1) {
            ret[order][order] = x;
            return;
        }
        for (vector<int>::size_type i = 0; i < size; ++i) {
            ret[order][order+i] = x++;
        }
        for (vector<int>::size_type i = 1; i < size; ++i) {
            ret[order+i][order+size-1] = x++;
        }
        for (vector<int>::size_type i = size-1; i > 0; --i) {
            ret[order+size-1][order+i-1] = x++;
        }
        for (vector<int>::size_type i = size-2; i > 0; --i) {
            ret[order+i][order] = x++;
        }
        generateMatrix(order+1, x, ret);
    }
};

int main(void)
{
    vector<vector<int> > ret = Solution().generateMatrix(3);
    for (vector<vector<int> >::iterator i = ret.begin(), iend = ret.end(); i != iend; ++i) {
        for (vector<int>::iterator j = i->begin(), jend = i->end(); j != jend; ++j) {
            cout << *j << " ";
        }
        cout << endl;
    }
    return 0;
}
