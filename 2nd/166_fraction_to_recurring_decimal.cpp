#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cstdint>
#include <cassert>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        if (denominator == 0)
            return "";
        ostringstream os;
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
            os << "-";
        uint64_t un = abs(numerator);
        uint64_t ud = abs(denominator);
        uint64_t integer = un / ud;
        uint64_t remainder = un % ud;
        os << integer;
        if (remainder == 0)
            return os.str();
        os << ".";
        sz_t idx = os.str().size();
        unordered_map<int, sz_t> um;
        while (remainder) {
            if (um[remainder]) {
                os << ")";
                break;
            }
            um[remainder] = idx++;
            remainder *= 10;
            os << remainder / ud;
            remainder %= ud;
        }
        if (remainder == 0)
            return os.str();
        return os.str().insert(um[remainder], 1, '(');
    }
    uint64_t abs(int32_t x) {
        int64_t y = x;
        return y > 0 ? y : -y;
    }
};

int main(void)
{
    Solution s;
    assert("0.5" == s.fractionToDecimal(1, 2));
    assert("2" == s.fractionToDecimal(2, 1));
    assert("0.(6)" == s.fractionToDecimal(2, 3));
    return 0;
}
