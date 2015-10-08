#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int atoi(char c) { return c - '0'; }
    int itoa(int a) { return a + '0'; }
    string multiply(string num1, string num2) {
        const int len1 = num1.size();
        const int len2 = num2.size();
        vector<int> res(len1+len2+1, 0);
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                res[i+j] += atoi(num1[len1-i-1]) * atoi(num2[len2-j-1]);
            }
        }
        int carry = 0;
        for (int i = 0; i < res.size(); ++i) {
            res[i] += carry;
            carry = res[i] / 10;
            res[i] %= 10;
        }
        int len = res.size();
        while (len > 0 && res[len-1] == 0)
            --len;
        if (len == 0)
            return "0";
        ostringstream os;
        for (int i = len; i > 0; --i) {
            os << res[i-1];
        }
        return os.str();
    }
};

int main(void)
{
    cout << Solution().multiply("123", "123") << endl;
    return 0;
}
