#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int r2i(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
    }
    int romanToInt(string s) {
        int ret = r2i(s[0]);
        if (1 == s.length())
            return ret;
        for (string::iterator iter = s.begin()+1; iter != s.end(); iter++) {
            if (r2i(*iter) > r2i(*(iter-1)))
                ret = ret - 2*r2i(*(iter-1)) + r2i(*iter);
            else
                ret += r2i(*iter);
        }
        return ret;
    }
};

int main(void)
{
    string s = "IV";
    cout << s << " -> " << Solution().romanToInt(s) << endl;
    return 0;
}
