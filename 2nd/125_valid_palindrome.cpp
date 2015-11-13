#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (string::iterator i = s.begin(), j = s.end(); i < j; ) {
            if (!isalnum(*i)) {
                ++i;
                continue;
            }
            if (!isalnum(*(j-1))) {
                --j;
                continue;
            }
            if (toupper(*i++) != toupper(*(--j)))
                return false;
        }
        return true;
    }
};

int main(void)
{
    Solution s;
    assert(s.isPalindrome("A man, a plan, a canal: Panama") && "'A man, a plan, a canal: Panama' is a palindrome");
    assert(!s.isPalindrome("race a car") && "'race a car' is not a palindrome");
    return 0;
}
