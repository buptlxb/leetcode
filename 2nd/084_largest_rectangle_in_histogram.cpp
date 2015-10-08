#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int ret = 0;
        stack<int> pendingHeights, indices;
        for (int i = 0, iend = height.size(); i < iend; ++i) {
            if (pendingHeights.empty() || pendingHeights.top() <= height[i]) {
                pendingHeights.push(height[i]);
                indices.push(i);
            } else {
                int last = 0;
                while (!pendingHeights.empty() && pendingHeights.top() > height[i]) {
                    ret = max(ret, pendingHeights.top()*(i-indices.top()));
                    last = indices.top();
                    pendingHeights.pop();
                    indices.pop();
                }
                if (pendingHeights.empty()) {
                    pendingHeights.push(height[i]);
                    indices.push(0);
                } else {
                    pendingHeights.push(height[i]);
                    indices.push(last);
                }
            }
        }
        while (!pendingHeights.empty()) {
            ret = max(ret, pendingHeights.top() *(static_cast<int>(height.size()) - indices.top()));
            pendingHeights.pop();
            indices.pop();
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
