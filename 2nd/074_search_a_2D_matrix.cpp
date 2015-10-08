#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size() == 1) {
            return binarySearch(matrix[0], target);
        }
        int top = 0, bottom = matrix.size()-1;
        while (top <= bottom) {
            int mid = top + (bottom-top)/2;
            if (matrix[mid].front() <= target && target <= matrix[mid].back())
                return binarySearch(matrix[mid], target);
            else if (target > matrix[mid].back())
                top = mid+1;
            else
                bottom = mid-1;
        }
        return false;
    }
    bool binarySearch(vector<int> &vec, int target) {
        int left = 0, right = vec.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (vec[mid] == target)
                return true;
            else if (vec[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        return false;
    }
};

int main(void)
{
    return 0;
}
