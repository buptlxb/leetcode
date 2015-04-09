#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::cout;

class Solution {
public:
    int findMin(vector<int> &num) {
        vector<int>::size_type left = 0;
        vector<int>::size_type right = num.size() - 1;
        vector<int>::size_type mid;
        do {
            if (num[left] <= num[right])
                return num[left];
            mid = (right - left) / 2 + left;
            if (num[mid] > num.back())
                left = mid + 1;
            else
                right = mid;
        } while ( left < right);
        return num[left];
    }
};

int main(void)
{
    vector<int> num;
    num.push_back(2);
    num.push_back(1);
    cout << Solution().findMin(num) << endl;
    return 0;
}
