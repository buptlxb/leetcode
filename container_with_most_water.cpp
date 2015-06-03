#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    typedef vector<int>::size_type size_type;
    int maxArea(vector<int>& height) {
        size_type left = 0, right = height.size()-1;
        int ret = 0;
        while (left < right) {
            int tmp = min(height[left], height[right]) * (right-left);
            if (ret < tmp)
                ret = tmp;
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return ret;
    }
    int min(int a, int b) {
        return a < b ? a :b;
    }
};

int main(void)
{
    int array[] = {1, 5, 5, 2};
    vector<int> vec(array, array+sizeof(array)/sizeof(int));
    cout << Solution().maxArea(vec) << endl;
    return 0;
}
