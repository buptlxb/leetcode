#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        spiralOrder(matrix, 0, ret);
        return ret;
    }
    void spiralOrder(vector<vector<int> > &matrix, int order, vector<int> &ret) {

        vector<vector<int> >::size_type row_size = matrix.size() - order * 2;

        if (row_size == 0)
            return;
        if (row_size == 1) {
            ret.insert(ret.end(), matrix[order].begin()+order, matrix[order].end()-order);
            return;
        }
        vector<int>::size_type col_size = matrix.front().size() - order * 2;
        if (col_size == 0)
            return;
        if (col_size == 1) {
            for(vector<vector<int> >::size_type i = 0; i < row_size; ++i) {
                ret.push_back(matrix[order+i][order]);
            }
            return;
        }

        for (vector<int>::size_type i = 0; i < col_size; ++i) {
            ret.push_back(matrix[order][order+i]);
        }
        for (vector<vector<int> >::size_type i = 1; i < row_size; ++i) {
            ret.push_back(matrix[order+i][order+col_size-1]);
        }
        for (vector<int>::size_type i = col_size-1; i > 0; --i) {
            ret.push_back(matrix[order+row_size-1][order+i-1]);
        }
        for (vector<vector<int> >::size_type i = row_size-2; i > 0; --i) {
            ret.push_back(matrix[order+i][order]);
        }
        spiralOrder(matrix, order+1, ret);
    }
};

int main(void)
{
    //int array1[] = {1, 2, 3};
    //int array2[] = {4, 5, 6};
    //int array3[] = {7, 8, 9};
    int array1[] = {1, 7};
    int array2[] = {2, 8};
    int array3[] = {3, 9};
    int array4[] = {4, 10};
    int array5[] = {5, 11};
    int array6[] = {6, 12};
    vector<int> a1(array1, array1+sizeof(array1)/sizeof(int));
    vector<int> a2(array2, array2+sizeof(array2)/sizeof(int));
    vector<int> a3(array3, array3+sizeof(array3)/sizeof(int));
    vector<int> a4(array4, array4+sizeof(array3)/sizeof(int));
    vector<int> a5(array5, array5+sizeof(array3)/sizeof(int));
    vector<int> a6(array6, array6+sizeof(array3)/sizeof(int));
    vector<vector<int> > matrix;
    matrix.push_back(a1);
    matrix.push_back(a2);
    matrix.push_back(a3);
    matrix.push_back(a4);
    matrix.push_back(a5);
    matrix.push_back(a6);
    vector<int> ret = Solution().spiralOrder(matrix);
    for (vector<int>::iterator i = ret.begin(), iend = ret.end(); i != iend; ++i) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
