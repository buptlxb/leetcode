#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums.begin(), nums.end(), k); 
    }   
    int findKthLargest(vector<int>::iterator first, vector<int>::iterator last, int k) {
        vector<int>::iterator begin = first;
        vector<int>::iterator end = last;
        int value = *first;
        --last;
        while (first < last) {
            while (first < last && value < *last)
                --last;
            if (first < last)
                *first++ = *last;
            while (first < last && !(value < *first))
                ++first;
            if (first < last)
                *last-- = *first;
        }   
        *first = value;
        if (end - first == k)
            return value;
        else if (end - first > k)
            return findKthLargest(first+1, end, k);
        else
            return findKthLargest(begin, first, k-(end-first)); 
    }   
};

int main(void)
{
    return 0;
}
