#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    typedef string::size_type sz_t;
    bool isPalindrome(const string &s, sz_t left, sz_t right) {
        while (left < right) {
            if (s[left++] == s[right--])
                continue;
            return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        if (s.empty())
            return s;
        sz_t left = 0, right = 0, len = 1;
        for (sz_t i = s.size()-1; i > 0; --i) {
            for (sz_t j = len; j <= i; ++j) {
                if (isPalindrome(s, i-j, i)) {
                    left = i-j;
                    right = i;
                    len = right - left + 1;
                }
            }

            for (sz_t j = (len+1)/2; j <= i; ++j) {
                if (i+j < s.size() && isPalindrome(s, i-j, i+j)) {
                    left = i-j;
                    right = i+j;
                    len = right - left + 1;
                }
            }
        }
        return s.substr(left, len);
    }
};

int main(void)
{
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    cout << Solution().longestPalindrome(s) << endl;
    // cout << Solution().isPalindrome(s, 0, 1) << endl;
    return 0;
}
