#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        const int len = s.size();
        stack<int> st;
        int last = -1;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(')
                st.push(i);
            else {
                if (st.empty())
                    last = i;
                else {
                    st.pop();
                    if (st.empty()) {
                        ret = max(ret, i-last);
                    } else {
                        ret = max(ret, i-st.top());
                    }
                }
            }
        }
        return ret;
    }
};

int main(void)
{
    cout << Solution().longestValidParentheses(")()(()))()())()()(())") << endl;
    return 0;
}
