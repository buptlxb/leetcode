#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
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
    int array[] = {2, 1, 5, 6, 2, 3};
    vector<int> height(array, array+sizeof(array)/sizeof(int));
    cout << Solution().largestRectangleArea(height) << endl;
    return 0;
}
