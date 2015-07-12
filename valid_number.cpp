#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        string::iterator iend = s.end();
        for (string::iterator i = s.begin(); i != iend; --iend) {
            if (!isspace(*(iend-1)))
                break;
        }
        enum InputType { INVALID, SPACE, SIGN, DIGIT, DOT, EXP };
        int transTable[9][6] = {
            -1, 0, 1, 2, 8, -1,
            -1, -1, -1, 2, 8, -1,
            -1, -1, -1, 2, 3, 5,
            -1, -1, -1, 4, -1, 5,
            -1, -1, -1, 4, -1, 5,
            -1, -1, 6, 7, -1, -1,
            -1, -1, -1, 7, -1, -1,
            -1, -1, -1, 7, -1, -1,
            -1, -1, -1, 4, -1, -1
        };
        int state = 0;
        for (string::iterator i = s.begin(); i != iend; ++i) {
            InputType input = INVALID;
            switch (*i) {
                case ' ':
                    input = SPACE;
                    break;
                case '+':
                case '-':
                    input = SIGN;
                    break;
                case '.':
                    input = DOT;
                    break;
                case 'e':
                case 'E':
                    input = EXP;
                    break;
                default:
                    if (isdigit(*i))
                        input = DIGIT;
            }
            state = transTable[state][input];
            cout << state << endl;
            if (state == -1)
                return false;
        }
        return state == 2 || state == 3 || state == 4 || state == 7;
    }
};

int main(void)
{
    string s(" 005047e+6");
    cout << Solution().isNumber(s) << endl;
}
