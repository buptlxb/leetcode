#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = nums1.size() + nums2.size();
        if (count % 2)
            return findKthElement(nums1, nums2, 0, nums1.size(), 0, nums2.size(), count/2+1);
        else
            return (findKthElement(nums1, nums2, 0, nums1.size(), 0, nums2.size(), count/2) + 
                    findKthElement(nums1, nums2, 0, nums1.size(), 0, nums2.size(), count/2+1)) / 2.0 ;
    }
    double findKthElement(vector<int> &nums1, vector<int> &nums2, int l1, int r1, int l2, int r2, int k) {
        int size1 = r1 - l1;
        int size2 = r2 - l2;
        if (size1 > size2)
            return findKthElement(nums2, nums1, l2, r2, l1, r1, k);
        if (size1 == 0)
            return nums2[l2+k-1];
        if (k == 1)
            return min(nums1[l1], nums2[l2]);
        int a = min(k/2, size1);
        int b = k - a;
        a += l1;
        b += l2;
        if (nums1[a-1] == nums2[b-1])
            return nums1[a-1];
        else if (nums1[a-1] < nums2[b-1]) {
            return findKthElement(nums1, nums2, a, r1, l2, r2, k-a+l1);
        } else {
            return findKthElement(nums1, nums2, l1, r1, b, r2, k-b+l2);
        }
    }
};

int main(void)
{
    vector<int> nums1(2, 1);
    vector<int> nums2(2, 1);
    nums1[1] = 2;
    nums2[1] = 2;
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
