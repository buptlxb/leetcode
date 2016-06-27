#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1 || num == 0)
            return true;
        int left = 0, right = num >> 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            unsigned long long tmp = mid * mid;
            if (tmp == num)
                return true;
            else if (tmp < num)
                left = mid+1;
            else
                right = mid-1;
        }
        return false;
    }
};

int main(void)
{
    return 0;
}
