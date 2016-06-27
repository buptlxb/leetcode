#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int ret = 0;
        stack<int> hgt;
        stack<vector<int>::size_type> idx;
        for (vector<int>::size_type i = 0, iend = height.size(); i < iend; ++i) {
            if (hgt.empty() || hgt.top() <= height[i]) {
                hgt.push(height[i]);
                idx.push(i);
            } else {
                vector<int>::size_type last = 0;
                while (!hgt.empty() && height[i] < hgt.top()) {
                    int tmp = hgt.top() * (i - idx.top());
                    if (ret < tmp)
                        ret = tmp;
                    last = idx.top();
                    hgt.pop();
                    idx.pop();
                }
                if (hgt.empty()) {
                    hgt.push(height[i]);
                    idx.push(0);
                } else {
                    hgt.push(height[i]);
                    idx.push(last);
                }
            }
        }
        while (!hgt.empty()) {
            int tmp = hgt.top() * (height.size() - idx.top());
            if (ret < tmp)
                ret = tmp;
            hgt.pop();
            idx.pop();
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
