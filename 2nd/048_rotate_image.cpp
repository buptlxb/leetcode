#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    void rotate(vector<vector<int> >& matrix) {
        rotate(matrix, 0); 
    }   
    void rotate(vector<vector<int> > &matrix, sz_t start) {
        const int len = matrix.size() - 2*start;
        if (len < 2)
            return;
        for (sz_t i = 0, iend = len-1; i < iend; ++i) {
            int tmp = matrix[start][start+i];
            matrix[start][start+i] = matrix[start+iend-i][start];
            matrix[start+iend-i][start] = matrix[start+iend][start+iend-i];
            matrix[start+iend][start+iend-i] = matrix[start+i][start+iend];
            matrix[start+i][start+iend] = tmp;
        }
        rotate(matrix, start+1);
    }   
};


int main(void)
{

    return 0;
}
