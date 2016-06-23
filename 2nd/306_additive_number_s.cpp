#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    string add(const string &lhs, const string &rhs) {
        sz_t i = lhs.size(), j = rhs.size();
        string rev;
        int carry = 0;
        while (i > 0 && j > 0) {
            int tmp = carry + lhs[--i]-'0' + rhs[--j]-'0';
            carry = tmp/10;
            rev.push_back(tmp%10+'0');
        }
        while (i > 0) {
            int tmp = carry  + lhs[--i]-'0';
            carry = tmp / 10;
            rev.push_back(tmp%10+'0');
        }
        while (j > 0) {
            int tmp = carry + rhs[--j]-'0';
            carry = tmp / 10;
            rev.push_back(tmp%10+'0');
        }
        if (carry)
            rev.push_back(carry+'0');
        return string(rev.rbegin(), rev.rend());
    }
    bool isAdditiveNumber(string num) {
        if (num.size() < 3)
            return false;
        for (sz_t i = 1, iend = num[0] == '0' ? 1 : num.size()-2; i <= iend; ++i) {
            for (sz_t j = 1, jend = num.size()-max(i, j); i + j <= jend; ++j) {
                if (j != 1 && num[i] == '0')
                    continue;
                if (isAdditiveNumber(num.substr(0, i), num.substr(i, j), num.substr(i+j)))
                    return true;
            }
        }
        return false;
    }
    bool isAdditiveNumber(const string &a, const string &b, const string &c) {
        string target = add(a, b);
        if (c.size() < target.size())
            return false;
        if (c.compare(0, target.size(), target) == 0 && c.size() == target.size())
            return true;
        return c[target.size()] != '0' && isAdditiveNumber(b, target, c.substr(target.size()));
    }
};

int main(void)
{
    return 0;
}
