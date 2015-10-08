#include <iostream>
#include <vector>

using namespace std;


class Solution {                                                                                                                                             
public:
    typedef vector<int>::size_type sz_t;
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        spiralOrder(matrix, 0, 0, ret);
        return ret;
    }   
    void spiralOrder(vector<vector<int> > &matrix, sz_t a, sz_t b, vector<int> &ret) {
        if (a + a + 1 > matrix.size())
            return;
        if (a + a + 1== matrix.size()) {
            ret.insert(ret.end(), matrix[a].begin()+b, matrix[a].end()-b);
            return;
        }   
        if (b + b + 1> matrix[a].size())  
            return;
        if (b + b + 1 == matrix[a].size()) {
            for (sz_t i = a, iend = matrix.size() - a; i < iend; ++i) {
                ret.push_back(matrix[i][b]);
            }   
            return;
        }   
        ret.insert(ret.end(), matrix[a].begin()+b, matrix[a].end()-b);
        for (sz_t i = a+1, iend = matrix.size() - a - 1; i < iend; ++i) {
            ret.push_back(matrix[i][matrix[a].size()-b-1]);
        }   
        ret.insert(ret.end(), matrix[matrix.size()-a-1].rbegin()+b, matrix[matrix.size()-a-1].rend()-b);
        for (sz_t i = matrix.size()-a-1; i > a+1; --i) {
            ret.push_back(matrix[i-1][b]);
        }   
        spiralOrder(matrix, a+1, b+1, ret);
    }   
};

int main(void)
{
    int a1[] = {1, 2, 3};
    int a2[] = {4, 5, 6};
    int a3[] = {7, 8, 9};
    vector<int> aa1(a1, a1+3);
    vector<int> aa2(a2, a2+3);
    vector<int> aa3(a3, a3+3);
    vector<vector<int> > matrix;
    matrix.push_back(aa1);
    matrix.push_back(aa2);
    matrix.push_back(aa3);
    vector<int> ret = Solution().spiralOrder(matrix);
    for (vector<int>::iterator i = ret.begin(), iend = ret.end(); i != iend; ++i) {
        cout << *i << ", ";
    }
    cout << endl;
    return 0;
}
