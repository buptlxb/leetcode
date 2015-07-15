#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.empty())
            return false;
        if (matrix.size() == 1)
            return binary_search(matrix.front().begin(), matrix.front().end(), target);
        vector<int>::size_type left = 0;
        vector<int>::size_type right = matrix.size()-1;
        while (left < right) {
            vector<int>::size_type mid = left + (right-left)/2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] > target) {
                if (mid == 0)
                    return false;
                left = mid-1;
            } else
                right = mid;
        }
        return binary_search(matrix[right].begin(), matrix[right].end(), target);
    }
};

int main(void)
{

    return 0;
}
