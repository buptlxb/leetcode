#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret(digits);
        int carry = 1;
        for (vector<int>::reverse_iterator i = ret.rbegin(), iend = ret.rend(); i != iend; ++i) {
            *i += carry;
            carry = *i / 10;
            *i %= 10;
        }
        if (carry)
            ret.insert(ret.begin(), carry);
        return ret;
    }
};

int main(void)
{
    return 0;
}
