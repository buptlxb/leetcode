#include <iostream>

using namespace std;

class Solution {
    public:
        string add(string a, string b) {
            int i = a.length() - 1;
            int j = b.length() - 1;
            char carry = 0;
            string ret;
            while (j >= 0) {
                char tmp = a[i] + b[j] - '0' - '0' + carry;
                ret.push_back(tmp % 2 + '0');
                carry = tmp / 2;
                i--;
                j--;
            }
            while (i >= 0) {
                char tmp = a[i] + carry - '0';
                ret.push_back(tmp % 2 + '0');
                carry = tmp / 2;
                i--;
            }
            if (carry)
                ret.push_back(carry + '0');
            return string(ret.rbegin(), ret.rend());
        }
        string addBinary(string a, string b) {
            if (a.length() > b.length())
                return add(a, b);
            else
                return add(b, a);
        }
};

int main(void)
{
    string s1 = "11";
    string s2 = "1";
    cout << Solution().addBinary(s1, s2) << endl;
    return 0;
}
