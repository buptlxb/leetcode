#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        if (s.size() == 0)
            return ret;
        stack<int> left;
        int last = -1;
        string::size_type len = s.size();
        for (string::size_type i = 0; i < len; ++i) {
            if (s[i] == '(')
                left.push(i);
            else {
                if (left.empty()) {
                    last = i;
                } else {
                    left.pop();
                    if (left.empty())
                        ret = ret > i-last ? ret : i-last;
                    else {
                        ret = ret > i-left.top() ? ret : i-left.top();
                    }
                }
            }
        }
        return ret;
    }
};

int main(void)
{
    string s;
    while (cin >> s) {
        cout << Solution().longestValidParentheses(s) << endl;
    }
    return 0;
}
