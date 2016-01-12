#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3)
            return false;
        return isAdditiveNumber("", "", num);
    }
    bool isAdditiveNumber(string a, string b, string remain) {
        cout << a << ":" << b << ":" << remain << endl;
        if (remain.size() == 0)
            return true;
        if (a.size() == 0) {
            for (string::size_type i = 1, iend = remain.size(); i*2 < iend; ++i) {
                if (isAdditiveNumber(remain.substr(0, i), b, remain.substr(i)))
                    return true;
                if (remain.front() == '0')
                    return false;
            }
        } else if (b.size() == 0) {
            for (string::size_type i = 1, iend = remain.size(); max(i, a.size()) + i <= iend; ++i) {
                if (isAdditiveNumber(a, remain.substr(0, i), remain.substr(i)))
                    return true;
                if (remain.front() == '0')
                    return false;
            }
        } else {
            string::size_type m = max(a.size(), b.size());
            string c = remain.substr(0, m);
            if (c.front() != '0' || c.size() != 1)
                if (add(a, b) == c && isAdditiveNumber(b, c, remain.substr(m)))
                    return true;
            c = remain.substr(0, m+1);
            if (c.front() != '0')
                if (add(a, b) == c && isAdditiveNumber(b, c, remain.substr(m+1)))
                    return true;
        }
        return false;
    }
    string add(string a, string b) {
        ostringstream os;
        auto i = a.rbegin(), j = b.rbegin();
        auto iend = a.rend(), jend = b.rend();
        int carry = 0;
        for (; i != iend && j != jend; ++i, ++j) {
            int tmp = c2i(*i) + c2i(*j) + carry;
            carry = tmp / 10;
            os << i2c(tmp % 10);
        }
        for (; i != iend; ++i) {
            int tmp = c2i(*i) + carry;
            carry = tmp / 10;
            os << i2c(tmp % 10);
        }
        for (; j != jend; ++j) {
            int tmp = c2i(*j) + carry;
            carry = tmp / 10;
            os << i2c(tmp % 10);
        }
        if (carry)
            os << i2c(carry);
        string r = os.str();
        return string(r.rbegin(), r.rend());
    }
    int c2i(char c) {
        return c - '0';
    }
    char i2c(int i) {
        return i + '0';
    }
};

int main(void)
{
    Solution s;
    // cout << s.isAdditiveNumber("112358") << endl;
    // cout << s.isAdditiveNumber("199100199") << endl;
    // cout << s.isAdditiveNumber("1023") << endl;
    // cout << s.isAdditiveNumber("1203") << endl;
    cout << s.isAdditiveNumber("123") << endl;
    return 0;
}
