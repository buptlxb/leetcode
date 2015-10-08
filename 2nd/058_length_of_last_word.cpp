#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0)
            return 0;
        string::size_type a(s.size()), b(s.size());
        for (string::size_type i = s.size(); i > 0; --i) {
            if (a == s.size() && s[i-1] == ' ')
                continue;
            if (a == s.size()) {
                a = b = i-1;
            } else if (s[i-1] != ' ') {
                b--;
            } else {
                break;
            }
        }
        cout << a <<  " " << b << endl;
        if (a != s.size())
            return a == b ? 1 : a-b+1;
        else
            return 0;
    }
};

int main(void)
{
    cout << Solution().lengthOfLastWord("heee      baaaa") << endl;
    return 0;
}
