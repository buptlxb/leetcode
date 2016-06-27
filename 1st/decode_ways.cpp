#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
        int a = 1;
        int b = 1;
        int c = 1;
        for (string::size_type i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (s[i-1] == '2' || s[i-1] == '1')
                    c = a;
                else
                    return 0;
            } else {
                if (s[i-1] == '0' || s[i-1] > '2')
                    c = b;
                else if (s[i-1] == '2' && s[i] > '6')
                    c = b;
                else
                    c = b + a;
            }
            a = b;
            b = c;
        }
        return b;
    }
};

int main(void)
{
    string s = "1222";
    cout << Solution().numDecodings(s) << endl;
    return 0;
}
