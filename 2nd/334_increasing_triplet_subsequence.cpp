#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = numeric_limits<int>::max();
        int b = a;
        for (auto x : nums) {
            if (x <= a)
                a = x;
            else if (x <= b)
                b = x;
            else 
                return true;
        }
        return false;
    }
};

int main(void)
{
    return 0;
}
