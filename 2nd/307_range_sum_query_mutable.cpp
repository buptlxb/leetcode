#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    vector<int> tree, singles;
public:
    NumArray(vector<int> &nums) : tree(nums.size()+1), singles(nums.size()+1) {
        for (int i = 0, iend = nums.size(); i < iend; ++i) {
            plus(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int diff = val - singles[i];
        plus(i, diff);
    }

    int sumRange(int i, int j) {
        if (i == j)
            return singles[i];
        return sum(j) - sum(i-1);
    }
    
    int sum(int i) {
        int ret = 0;
        ++i;
        for (; i > 0; i -= i & -i)
            ret += tree[i];
        return ret;
    }
    
    void plus(int i, int val) {
        singles[i] += val;
        ++i;
        for (int iend = tree.size(); i < iend; i += i & -i) {
            tree[i] += val;
        }
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

int main(void)
{
    vector<int> nums{1, 3, 5, 7, 9, 11};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << endl;
    return 0;
}
