#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    int trap(vector<int>& height) {
        int ret = 0;
        s_t size = height.size();
        if (height.size() < 3)
            return 0;
        s_t i = 0;
        while (i < size && !height[i])
            ++i;
        stack<int> s;
        for (; i < size; ++i) {
            if (s.empty() || height[i] < height[s.top()]) {
                s.push(i);
            } else if (s.size() == 1) {
                s.pop();
                s.push(i);
            } else {
                s_t base = s.top();
                do {
                    s.pop();
                    s_t left = s.top();
                    ret += (min(height[left], height[i]) - height[base]) * (i - left - 1);
                    base = left;
                } while (s.size() > 1 && height[base] < height[i]);
                if (height[i] >= height[base]) {
                    s.pop();
                }
                s.push(i);
            }
        }
        return ret;
    }
};

int main(void)
{
    int a[] = {5,5,1,7,1,1,5,2,7,6};
    //int a[] = {5,2,1,2,1,5};
    vector<int> height(a, a+sizeof(a)/sizeof(int));
    cout << Solution().trap(height) << endl;
    return 0;
}
