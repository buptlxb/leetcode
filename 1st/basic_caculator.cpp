#include <iostream>
#include <stack>
#include <cctype>
#include <queue>

using namespace std;

class Solution {
public:
    typedef stack<int> OperandS;
    typedef stack<char> OperatorS;
    typedef string::size_type s_t;
    int calculate(string s) {
        int tmp = 0;
        OperandS opds;
        OperatorS oprs;
        for (s_t i = 0, iend = s.size(); i < iend; ++i) {
            if (isdigit(s[i])) {
                while (i < iend && isdigit(s[i])) {
                    tmp = tmp*10 + s[i] - '0';
                    ++i;
                }
                --i;
                opds.push(tmp);
                tmp = 0;
            } else if (s[i] == '(')
                oprs.push(s[i]);
            else if (s[i] == ')') {
                while (!oprs.empty() && oprs.top() != '(') {
                    calc(opds, oprs);
                }
                oprs.pop();
            } else if (isspace(s[i]))
                ;
            else {
                while (!oprs.empty() && !less(oprs.top(), s[i])) {
                    calc(opds, oprs);
                }
                oprs.push(s[i]);
            }
        }
        while (!oprs.empty()) {
            calc(opds, oprs);
        }
        return opds.top();
    }
    bool less(char lhs, char rhs) {
        if (lhs == '(')
            return true;
        else
            return false;
    }
    void calc(OperandS &opds, OperatorS &oprs) {
        int rhs = opds.top();
        opds.pop();
        int lhs = opds.top();
        opds.pop();
        char op = oprs.top();
        oprs.pop();
        cout << lhs << op << rhs << endl;
        switch (op) {
            case '+':
                opds.push(lhs + rhs);
                break;
            case '-':
                opds.push(lhs - rhs);
                break;
            default:
                cout << "error" << endl;
        }
    }
};

int main(void)
{
    cout << Solution().calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << Solution().calculate("0") << endl;
    cout << Solution().calculate(" 0 ") << endl;
    cout << Solution().calculate("( 0 ) ") << endl;
    return 0;
}
