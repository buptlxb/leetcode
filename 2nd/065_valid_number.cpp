#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isNumber(string str) {
        enum State {ZERO=0, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN};
        State s = ZERO;
        for (string::iterator i = str.begin(), iend = str.end(); i != iend; ++i) {
            if (isspace(*i)) {
                switch (s) {
                    case ZERO:
                        break;
                    case TWO: case THREE: case FOUR: case SIX: case SEVEN:
                        s = EIGHT;
                        break;
                    case EIGHT:
                        break;
                    default:
                        return false;
                }
            } else if (*i == '-' || *i == '+') {
                switch (s) {
                    case ZERO:
                        s = ONE;
                        break;
                    case FIVE:
                        s = SIX;
                        break;
                    default:
                        return false;
                }
            } else if (*i == '.') {
                switch (s) {
                    case ZERO:
                        s = NINE;
                        break;
                    case ONE:
                        s = TEN;
                        break;
                    case TWO:
                        s = THREE;
                        break;
                    default:
                        return false;
                }
            } else if (isdigit(*i)) {
                switch (s) {
                    case ZERO: case ONE:
                        s = TWO;
                        break;
                    case TWO: case FOUR: case SEVEN:
                        break;
                    case THREE:
                        s = FOUR;
                        break;
                    case FIVE: case SIX:
                        s = SEVEN;
                        break;
                    case NINE: case TEN:
                        s = FOUR;
                        break;
                    default:
                        return false;
                }
            } else if (*i == 'e') {
                switch (s) {
                    case TWO: case THREE: case FOUR:
                        s = FIVE;
                        break;
                    default:
                        return false;
                }
            } else {
                return false;
            }
        }
        return s != ZERO && s != ONE && s != FIVE  && s != SIX && s != NINE && s != TEN;
    }
};


int main(void)
{
    Solution s;
    assert(s.isNumber("0"));
    assert(s.isNumber(" 0.1 "));
    assert(!s.isNumber("abc"));
    assert(!s.isNumber("1 a"));
    assert(s.isNumber("2e10"));
    assert(s.isNumber(".1"));
    assert(!s.isNumber("."));
    assert(s.isNumber("1    "));
    assert(s.isNumber("1.   "));
    assert(!s.isNumber("4e+"));
    assert(!s.isNumber(" -."));
    assert(s.isNumber("46.e3"));
    return 0;
}
