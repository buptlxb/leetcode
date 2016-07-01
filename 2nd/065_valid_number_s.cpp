#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isNumber(const string &s, bool dot) {
        if (s.size() == 0)
            return false;
        string::size_type i = 0, iend = s.size();
        if (s[i] == '+' || s[i] == '-')
            ++i;
        bool digit = false;
        for ( ; i < iend; ++i) {
            if (isdigit(s[i]))
                digit = true;
            else if (!dot && s[i] == '.')
                dot = true;
            else
                return false;
        }
        return digit;
    }
    bool isNumber(string s) {
        string::size_type i = 0, j = 0, iend = s.size();
        while (i < iend && s[i] == ' ')
            ++i;
        while (i < iend && s[iend-1] == ' ')
            --iend;
        j = i;
        while (j < iend && s[j] != 'e')
            ++j;
        if (j == iend)
            return isNumber(s.substr(i, j-i), false);
        else
            return isNumber(s.substr(i, j-i), false) && isNumber(s.substr(j+1, iend-j-1), true);
    }
};

int main(void)
{
    return 0;
}
