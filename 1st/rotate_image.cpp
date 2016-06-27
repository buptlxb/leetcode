#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
       if (matrix.size() < 2)
           return;
       vector<int>::size_type n = matrix.size();
       for (vector<vector<int> >::size_type i = 0, iend = n >> 1; i != iend; ++i) {
           for (vector<int>::size_type j = 0, jend = (n+1) >> 1; j != jend; ++j) {
               int tmp = matrix[j][n-1-i];
               matrix[j][n-1-i] = matrix[i][j];
               matrix[i][j] = matrix[n-1-j][i];
               matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
               matrix[n-1-i][n-1-j] = tmp;
           }
       }
    }
};

ostream & operator<< (ostream &os, vector<vector<int> > matrix) {
    for (vector<vector<int> >::iterator i = matrix.begin(), iend = matrix.end(); i != iend; ++i) {
        for (vector<int>::iterator j = i->begin(), jend = i->end(); j != jend; ++j) {
            os << *j << " ";
        }
        os << endl;
    }
    return os;
}

int main(void)
{
    int a1[] = {1, 2, 3};
    int a2[] = {4, 5, 6};
    int a3[] = {7, 8, 9};
    vector<int> v1(a1, a1+3);
    vector<int> v2(a2, a2+3);
    vector<int> v3(a3, a3+3);
    vector<vector<int> > matrix;
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    Solution().rotate(matrix);
    cout << matrix << endl;
    return 0;
}
