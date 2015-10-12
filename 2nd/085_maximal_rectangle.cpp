#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int maximalRectangle(vector<vector<char> >& matrix) {
        int ret = 0;
        if (matrix.empty())
            return ret;
        vector<int> height(matrix.front().size());
        for (sz_t i = 0, iend = matrix.size(); i < iend; ++i) {
            for (sz_t j = 0, jend = matrix[i].size(); j < jend; ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
            }
            ret = max(ret, maximalRectangle(height));
        }
        return ret;
    }
    int maximalRectangle(vector<int> &height) {
        stack<int> pending;
        sz_t ret = 0;
        for (sz_t i = 0, iend = height.size(); i < iend; ++i) {
            if (pending.empty() || height[pending.top()] <= height[i]) {
                pending.push(i);
            } else {
                int index = pending.top();
                pending.pop();
                ret = max(ret, (pending.empty() ? i : i-pending.top()-1)*height[index]);
                pending.pop();
                --i;
            }
        }
        while (!pending.empty()) {
            int index = pending.top();
            pending.pop();
            ret = max(ret, (pending.empty() ? height.size() : height.size()-pending.top()-1)*height[index]);
        }
        return ret;
    }
};

int main(void)
{
    vector<vector<char> > matrix(1, vector<char>(1, '0'));
    cout << Solution().maximalRectangle(matrix) << endl;
    return 0;
}
