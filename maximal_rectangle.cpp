#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int ret = 0;
        if (matrix.empty())
            return ret;
        vector<int> height(matrix.front().size(), 0);
        for (vector<vector<char> >::size_type i = 0, iend = matrix.size(); i < iend; ++i) {
            for (vector<char>::size_type j = 0, jend = matrix[i].size(); j < jend; ++j) {
                height[j] = matrix[i][j] == '1' ? 1 + height[j] : 0;
            }
            int tmp = largestRectangle(height);
            if (ret < tmp)
                ret = tmp;
        }
        return ret;
    }

    int largestRectangle(vector<int> height) {
        int ret = 0;
        stack<int> candidates;
        for (vector<int>::size_type i = 0, iend = height.size(); i < iend; ++i) {
            if (candidates.empty() || height[candidates.top()] < height[i]) {
                candidates.push(i);
            } else {
                int index = candidates.top();
                candidates.pop();
                int tmp = height[index] * (candidates.empty() ? i : i - candidates.top() - 1);
                if (tmp > ret)
                    ret = tmp;
                --i;
            }
        }
        while (!candidates.empty()) {
            int index = candidates.top();
            candidates.pop();
            int tmp = height[index] * (candidates.empty() ? height.size() : height.size() - candidates.top() -1);
            if (tmp > ret)
                ret = tmp;
        }
        return ret;
    }
};

int main(void)
{
    char array[] = {'1', '1', '0', '1'};
    vector<char> vec(array, array+sizeof(array)/sizeof(char));
    vector<vector<char> > matrix;
    matrix.push_back(vec);
    matrix.push_back(vec);
    matrix.push_back(vec);
    matrix.push_back(vec);
    cout << Solution().maximalRectangle(matrix) << endl;
    return 0;
}
