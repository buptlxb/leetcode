#include <iostream>

using namespace std;

class Solution {
public:
    void reverse(int nums[], int left, int right) {
        while (left < right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }

    void rotate(int nums[], int n, int k) {
        k %= n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
};

void print_array(int nums[], int len)
{
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(nums) / sizeof(nums[0]);
    print_array(nums, len);
    Solution().rotate(nums, len, 3);
    print_array(nums, len);
    return 0;
}
