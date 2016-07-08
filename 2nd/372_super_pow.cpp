#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;
        int start = 0;
        int ret = 1;
        a %= 1337;
        while (start != b.size()) {
            if (b.back() % 2)
                ret = (ret * a) % 1337;
            a = (a * a) % 1337;
            shift(b, start);
        }
        return ret;
    }
    void shift(vector<int> &b, int &start) {
        int carry = 0;
        for (int i = start; i < b.size(); ++i) {
            int tmp = (carry*10 + b[i]) >> 1;
            carry = b[i] % 2;
            b[i] = tmp;
        }
        start += b[start] == 0;
    }
};

int main(void)
{
    Solution s;
    vector<int> b1{3}, b2{1, 0};
    cout << s.superPow(2, b1) << endl;
    cout << s.superPow(2, b2) << endl;
    return 0;
}
