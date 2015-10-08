#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <climits>

using namespace std;

class Solution {
public:
    typedef string::size_type s_t;
    string fractionToDecimal(int numerator, int denominator) {
        ostringstream fraction;
        map<int, s_t> m;
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
            fraction << "-";
            
        long num= numerator < 0 ? -(long)numerator : numerator;
        long den = denominator < 0 ? -(long)denominator : denominator;
        long integer = (long)num / den;
        long remainder = (long)num % den;
        map<int, s_t>::iterator found;
        fraction << integer;
        if (remainder == 0)
            return fraction.str();
        fraction << ".";
        s_t i = fraction.str().size();
        while (remainder) {
            found = m.find(remainder);
            if (found != m.end()) {
                fraction << ')';
                break;
            }
            int t = remainder*10 / den;
            m[remainder] = i++;
            fraction << t;
            remainder = remainder*10 % den;
        }
        if (remainder == 0)
            return fraction.str();
        return fraction.str().insert(found->second, 1, '(');
    }
};

int main(void)
{
    cout << Solution().fractionToDecimal(2, 3) << endl;
    cout << Solution().fractionToDecimal(1, 6) << endl;
    cout << Solution().fractionToDecimal(1, 5) << endl;
    cout << Solution().fractionToDecimal(-1, 5) << endl;
    cout << Solution().fractionToDecimal(INT_MIN, -1) << endl;
    return 0;
}
