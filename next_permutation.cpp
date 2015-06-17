#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        vector<int>::size_type i = 0, left = 0, right;
        while (i+1 < nums.size()) {
            if (nums[i] < nums[i+1])
                left = i;
            ++i;
        }
        if (nums[left] < nums[left+1]) {
            right = left + 1;
            i = left + 2;
            while (i < nums.size()) {
                if (nums[i] > nums[left] && nums[i] < nums[right])
                    right = i;
                ++i;
            }
            swap(nums[left], nums[right]);
            sort(nums.begin()+left+1, nums.end());
        } else {
            sort(nums.begin(), nums.end());
        }
    }
};

template <typename T>
ostream & operator<< (ostream &os, vector<T> vec)
{
    os << "[ ";
    for (typename vector<T>::iterator i = vec.begin(), iend = vec.end(); i != iend; ++i) {
        os << *i << " ";
    }
    os << "]";
}

int main(void)
{
    int array[] = {2, 3, 1};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    Solution().nextPermutation(nums);
    cout << nums << endl;
    return 0;
}
