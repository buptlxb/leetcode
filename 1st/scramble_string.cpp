#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    typedef string::size_type s_t;
    bool isScramble(string s1, string s2) {
        return isScramble(s1, s2, 0, s1.size(), 0, s2.size());
    }
    bool isScramble(string &s1, string &s2, s_t l1, s_t r1, s_t l2, s_t r2) {
        if (l1 == r1 && l2 == r2)
            return true;
        s_t len1 = r1 - l1;
        s_t len2 = r2 - l2;
        if (len1 == 1 && len2 == 1)
            return s1[l1] == s2[l2];
        if (len1 != len2)
            return false;
        string sorted_s1(s1.begin()+l1, s1.begin()+r1);
        string sorted_s2(s2.begin()+l2, s2.begin()+r2);
        sort(sorted_s1.begin(), sorted_s1.end());
        sort(sorted_s2.begin(), sorted_s2.end());
        if (sorted_s1 != sorted_s2)
            return false;
        for (s_t i = 1; i < len1; ++i) {
            if (isScramble(s1, s2, l1, l1+i, l2, l2+i) && isScramble(s1, s2, l1+i, r1, l2+i, r2))
                return true;
            if (isScramble(s1, s2, l1, l1+i, r2-i, r2) && isScramble(s1, s2, l1+i, r1, l2, r2-i))
                return true;
        }
        return false;
    }
}; 
int main(void)
{
    //cout << Solution().isScramble("rgtae", "great") << endl;
    cout << Solution().isScramble("aa", "ab") << endl;
    return 0;
}
