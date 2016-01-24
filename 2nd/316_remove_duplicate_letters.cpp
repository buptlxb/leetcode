#include <iostream>
#include <stack>
#include <cassert>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> m(26), n(26);
        for (auto c : s)
            ++m[c-'a'];
        vector<char> st;

        for (auto c : s) {
            --m[c-'a'];
            if (n[c-'a'])
                continue;
            while (!st.empty() && st.back() >= c && m[st.back()-'a']) {
                n[st.back()-'a'] = 0;
                st.pop_back();
            }
            n[c-'a'] = 1;
            st.push_back(c);
        }
        return string(st.begin(), st.end());
    }
};

int main(void)
{
    Solution s;
    assert("abc" == s.removeDuplicateLetters("bcabc"));
    assert("acdb" == s.removeDuplicateLetters("cbacdcbc"));
    cout << s.removeDuplicateLetters("baa") << endl;
    cout << s.removeDuplicateLetters("bbcaac") << endl;
    cout << s.removeDuplicateLetters("bbbacacca") << endl;
    cout << s.removeDuplicateLetters("abacb") << endl;
    return 0;
}
