#include <iostream>
#include <cctype>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string str) {
            char *buf = new char[str.length()+1];
            int i = 0;
            for (string::iterator iter = str.begin(); iter != str.end(); iter++) {
                if (isalnum(*iter))
                    buf[i++] = tolower(*iter);
            }
            int start = 0;
            int end = i - 1;
            while (start <= end) {
                if (buf[start++] != buf[end--])
                    return false;
            }
            return true;
            delete []buf;
        }
};

int main(void)
{
    string str = "A man, a plan, a canal: Panama";
    str = "race a car";
    cout << "Is " << str << " palindrome?" << Solution().isPalindrome(str) << endl;
    return 0;
}
