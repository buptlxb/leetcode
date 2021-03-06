#include <iostream>

using namespace std;

void swap(int nums[], int left, int right, int len)
{
    for (int i = 0; i < len; ++i) {
        int tmp = nums[left+i];
        nums[left+i] = nums[right+i];
        nums[right+i] = tmp;
    }
}

void block_swap(int nums[], int left, int right)
{
    if (left == right) {
        swap(nums, 0, left, left);
    } else if (left < right) {
        swap(nums, 0, right, left);
        block_swap(nums, left, right - left);
    } else {
        swap(nums, 0, left, right);
        block_swap(nums + right, left - right,  right);
    }
}

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
    block_swap(nums, 4, 3);
    print_array(nums, len);
    return 0;
}
