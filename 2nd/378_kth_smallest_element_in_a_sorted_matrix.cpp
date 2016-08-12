#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty())
            return 0;
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int cnt = 0;
            int mid = left + (right - left) / 2;
            for (int i = 0; i < matrix.size(); ++i)
                cnt += distance( matrix[i].begin(), upper_bound(matrix[i].begin(), matrix[i].end(), mid));
            if (cnt < k)
                left = mid + 1;
            else
                right = mid;
        }   
        return left;
    }   
};

int main(void)
{
    return 0;
}
