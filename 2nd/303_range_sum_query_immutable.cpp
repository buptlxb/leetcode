#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    vector<int> sums;
public:
    typedef vector<int>::size_type sz_t;
    NumArray(vector<int> &nums) : sums(nums.size()+1) {
        for (sz_t i = 0, iend = nums.size(); i < iend; ++i)
            sums[i+1] = nums[i] + sums[i];
    }

    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main(void)
{
    vector<int> nums{-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;
    return 0;
}
