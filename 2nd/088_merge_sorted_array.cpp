#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (nums1[i-1] > nums2[j-1]) {
                nums1[i+j-1] = nums1[i-1];
                --i;
            } else {
                nums1[i+j-1] = nums2[j-1];
                --j;
            }
        }
        while (i > 0) {
            nums1[i+j-1] = nums1[i-1];
            --i;
        }
        while (j > 0) {
            nums1[i+j-1] = nums2[j-1];
            --j;
        }
    }
};

int main(void)
{
    return 0;
}
