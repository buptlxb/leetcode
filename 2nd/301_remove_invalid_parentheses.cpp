#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    int max_lefts;
public:
    Solution() : max_lefts(0) {}
    typedef vector<int>::size_type sz_t;
    vector<string> removeInvalidParentheses(string s) {
        set<string> res;
        max_lefts = 0;
        removeInvalidParentheses(s, "", 0, 0, res);
        vector<string> ret(res.begin(), res.end());
        if (ret.empty())
            ret.push_back("");
        return ret;
    }
    void removeInvalidParentheses(string s, string part, int lcount, int mlcount, set<string> &res) {
        if (s.empty()) {
            if (lcount == 0) {
                max_lefts = max(max_lefts, mlcount);
                if (mlcount == max_lefts) {
                    res.insert(part);
                }
            }
            return;
        } 
        string next = s.substr(1);
        if (s.front() == '(') {
            removeInvalidParentheses(next, part+s.front(), lcount+1, mlcount+1, res);
            removeInvalidParentheses(next, part, lcount, mlcount, res);
        } else if (s.front() == ')') {
            if (lcount > 0)
                removeInvalidParentheses(next, part+s.front(), lcount-1, mlcount, res);
            removeInvalidParentheses(next, part, lcount, mlcount, res);
        } else {
            removeInvalidParentheses(next, part+s.front(), lcount, mlcount, res);
        }
    }
};

int main(void)
{
    Solution s;
    for (auto x : s.removeInvalidParentheses("()())()"))
        cout << x << endl;
    cout << "------------" << endl;
    for (auto x : s.removeInvalidParentheses("(a)())()"))
        cout << x << endl;
    cout << "------------" << endl;
    for (auto x : s.removeInvalidParentheses(")("))
        cout << x << endl;
    cout << "------------" << endl;
    for (auto x : s.removeInvalidParentheses("()()()))()"))
        cout << x << endl;
    cout << "------------" << endl;
    for (auto x : s.removeInvalidParentheses("h)))uq))v)))))))()"))
        cout << x << endl;
    cout << "------------" << endl;
    for (auto x : s.removeInvalidParentheses("))"))
        cout << x << endl;
    cout << "------------" << endl;
    for (auto x : s.removeInvalidParentheses("(("))
        cout << x << endl;
    cout << "------------" << endl;
    for (auto x : s.removeInvalidParentheses(")d))"))
        cout << x << endl;
    cout << "------------" << endl;
    for (auto x : s.removeInvalidParentheses(")()("))
        cout << x << endl;
    return 0;
}
