#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int trap(vector<int>& height) {
        stack<int> lefts;
        int ret = 0;
        for (sz_t i = 0, iend = height.size(); i < iend; ++i) {
            if (lefts.empty() || height[lefts.top()] > height[i])
                lefts.push(i);
            else if (lefts.size() == 1) {
                lefts.pop();
                lefts.push(i);
            } else {
                int base = lefts.top();
                do {
                    lefts.pop();
                    ret += (min(height[i], height[lefts.top()]) - height[base]) * (i - lefts.top() - 1);
                    base = lefts.top();
                } while (lefts.size() > 1 && height[i] >= height[base]);
                if (height[i] >= height[base])
                    lefts.pop();
                lefts.push(i);
            }
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
