#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;
using std::pair;

class Solution {
public:
    int calc(int n) {
        int ret = 0;
        while (n) {
            int tmp = n % 10;
            ret += tmp * tmp;
            n /= 10;
        }
        return ret;
    }

    bool isHappy(int n) {
        set<int> nums;
        while (n != 1) {
            pair<set<int>::iterator, bool> p = nums.insert(n);
            if (p.second)
                n = calc(n);
            else
                return false;
        }
        return true;
    }
};

int main(void)
{
    cout << Solution().isHappy(19) << endl;
    return 0;
}
