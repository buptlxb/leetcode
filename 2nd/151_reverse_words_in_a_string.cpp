#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty())
            return;
        istringstream is(s);
        stack<string> st;
        string tmp;
        while (is >> tmp) {
            st.push(tmp);
        }
        ostringstream os;
        if (st.empty()) {
            s = os.str();
            return;
        }
        os << st.top();
        st.pop();
        while (!st.empty()) {
            os << " " << st.top();
            st.pop();
        }
        s = os.str();
    }
};

int main(void)
{
    string s = " ";
    Solution().reverseWords(s);
    cout << s << endl;
    return 0;
}
