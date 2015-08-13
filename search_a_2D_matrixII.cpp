#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.empty())
            return false;
        return searchMatrix(matrix, 0, 0, matrix.size()-1, matrix.front().size()-1, target);
    }
    bool searchMatrix(vector<vector<int> >& matrix, s_t top, s_t left, s_t bottom, s_t right, int target) {
        if (bottom < top || right < left)
            return false;
        s_t row_mid = top + (bottom-top)/2;
        s_t col_mid = left + (right-left)/2;
        if (matrix[row_mid][col_mid] == target)
            return true;
        else if (matrix[row_mid][col_mid] < target) {
            return searchMatrix(matrix, top, col_mid+1, row_mid, right, target)
                || searchMatrix(matrix, row_mid+1, left, bottom, right, target);
        } else {
            if (!col_mid && !row_mid)
                return false;
            else if (!col_mid)
                return searchMatrix(matrix, top, left, row_mid-1, right, target);
            else if (!row_mid)
                return searchMatrix(matrix, row_mid, left, bottom, col_mid-1, target);
            else
                return searchMatrix(matrix, top, left, row_mid-1, right, target)
                    || searchMatrix(matrix, row_mid, left, bottom, col_mid-1, target);
        }
    }
};

int main(void)
{
    int a1[] = {1,   4,  7, 11, 15};
    int a2[] = {2,   5,  8, 12, 19};
    int a3[] = {3,   6,  9, 16, 22};
    int a4[] = {10, 13, 14, 17, 24};
    int a5[] = {18, 21, 23, 26, 30};
    vector<int> v1 (a1, a1+sizeof(a1)/sizeof(int));
    vector<int> v2 (a2, a2+sizeof(a2)/sizeof(int));
    vector<int> v3 (a3, a3+sizeof(a3)/sizeof(int));
    vector<int> v4 (a4, a4+sizeof(a4)/sizeof(int));
    vector<int> v5 (a5, a5+sizeof(a5)/sizeof(int));
    vector<vector<int> > matrix;
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);
    matrix.push_back(v5);
    cout << boolalpha << Solution().searchMatrix(matrix, 5) << endl;
    cout << boolalpha << Solution().searchMatrix(matrix, 20) << endl;
    return 0;
}
