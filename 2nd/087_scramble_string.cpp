#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    bool isScramble(string s1, string s2) {
        return isScramble(s1, 0, s1.size(), s2, 0, s2.size());
    }
    bool isScramble(const string &s1, sz_t a1, sz_t b1, const string &s2, sz_t a2, sz_t b2) {
        if (b1 != b2)
            return false;
        if (b2 == 0)
            return true;
        if (b2 == 1)
            return s1[a1] == s2[a2];
        string ss1(s1.begin()+a1, s1.begin()+a1+b1), ss2(s2.begin()+a2, s2.begin()+a2+b2);
        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        if (ss1 != ss2)
            return false;
        for (sz_t i = 1, iend = b1; i < b1; ++i) {
            if (isScramble(s1, a1, i, s2, a2, i) && isScramble(s1, a1+i, b1-i, s2, a2+i, b2-i))
                return true;
            if (isScramble(s1, a1, i, s2, a2+b2-i, i) && isScramble(s1, a1+i, b1-i, s2, a2, b2-i))
                return true;
        }
        return false;
    }
};

int main(void)
{
    return 0;
}
