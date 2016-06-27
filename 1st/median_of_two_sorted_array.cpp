#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::iterator idx_t;
    typedef vector<int>::size_type sz_t;
    double findKthMin(idx_t al, idx_t ar, idx_t bl, idx_t br, sz_t k) {
        sz_t asize = ar - al;
        sz_t bsize = br - bl;
        if (asize > bsize)
            return findKthMin(bl, br, al, ar, k);
        if (asize == 0)
            return *(bl + k - 1);
        if (k == 1)
            return *al < *bl ? *al : *bl;

        sz_t ma = k/2 > asize ? asize : k/2;
        sz_t mb = k - ma;
        if (*(al + ma - 1) < *(bl + mb -1))
            return findKthMin(al + ma, ar, bl, br, k-ma);
        else if (*(al + ma - 1) > *(bl + mb -1))
            return findKthMin(al, ar, bl + mb, br, k-mb);
        else
            return *(al + ma - 1);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        sz_t total = nums1.size() + nums2.size();
        if (total % 2)
            return findKthMin(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), total/2+1);
        else
            return (findKthMin(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), total/2) +
                    findKthMin(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), total/2+1)) / 2;
    }
};

int main(void)
{
    int a[] = {1, 2, 3, 4};
    int b[] = {1, 2, 3, 4};
    vector<int> va(a, a+sizeof(a)/sizeof(int));
    vector<int> vb(b, b+sizeof(b)/sizeof(int));
    cout << Solution().findMedianSortedArrays(va, vb) << endl;
    return 0;
}
