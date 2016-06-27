#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

class Solution {
    private :
        bool isOperand (const string &token) {
            if (token.length() != 1)
                return true;
            if (!token.compare("+") || !token.compare("-")
                    || !token.compare("*") || !token.compare("/")) {
                return false;
            }
            return true;
        }
    public :
        int evalRPN (vector<string> &tokens) {
            stack<int> operands;
            for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
                if (isOperand(*it)) {
                    operands.push(atoi(it->c_str()));
                }
                else {
                    int b = operands.top();
                    operands.pop();
                    int a = operands.top();
                    operands.pop();
                    switch (it->at(0)) {
                        case '+' :
                            operands.push(a+b);
                            break;
                        case '-' :
                            operands.push(a-b);
                            break;
                        case '*' :
                            operands.push(a*b);
                            break;
                        case '/' :
                            operands.push(a/b);
                            break;
                        default:
                            cerr << "unknown operator" << endl;
                            exit(-1);
                    }
                }
            }
            return operands.top();
        }
};

int main(void)
{
    vector<string> tokens;
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");

    Solution s;
    cout << s.evalRPN(tokens) << endl;
    return 0;
}
