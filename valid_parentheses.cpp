#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    bool isLeft(char c) {
        return c == '(' || c == '[' || c == '{';
    }
    bool isMatch(char a, char b) {
        return a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}';
    }
    bool isValid(string s) {
        vector<char> stack;
        for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
            if (isLeft(*iter))
                stack.push_back(*iter);
            else if(stack.empty())
                return false;
            else if (isMatch(stack.back(), *iter))
                    stack.pop_back();
            else {
                return false;
            }
        }
        if (stack.empty())
            return true;
        return false;
    }
};

int main(void)
{
    string str = "]";
    cout << Solution().isValid(str) << endl;
    return 0;
}
