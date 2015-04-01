#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            int carry, tmp;
            for (vector<int>::reverse_iterator iter = digits.rbegin(); iter != digits.rend(); iter++) {
                tmp = *iter + 1;
                carry = tmp / 10;
                *iter = tmp % 10;
                if (!carry)
                    break;
            }
            if (carry)
                digits.insert(digits.begin(), 1);
            return digits;
        }
};

int main(void)
{
    vector<int> vec(5, 8);
    vector<int> ret = Solution().plusOne(vec);
    for (vector<int>::iterator iter = ret.begin(); iter != ret.end(); iter++) {
        cout << *iter;
    }
    cout << endl;
    return 0;
}
