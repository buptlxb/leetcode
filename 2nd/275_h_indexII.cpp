#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        return hIndex(citations.begin(), citations.end(), citations.end());
    }
    int hIndex(vector<int>::iterator first, vector<int>::iterator last, vector<int>::iterator end) {
        if (!(first < last))
            return 0;
        vector<int>::iterator mid = first + distance(first, last)/2;
        int num = distance(mid, end);
        if (*mid == num)
            return *mid;
        else if (*mid < num)
            return max(hIndex(mid+1, last, end), int(*mid));
        else
            return max(hIndex(first, mid, end), int(num));
    }
};

int main(void)
{
    Solution s;
    vector<int> citations{0, 1, 2, 5, 6};
    assert(s.hIndex(citations) == 2);
    return 0;
}
