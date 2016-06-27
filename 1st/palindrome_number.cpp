#include <iostream>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0)
                return false;
            if (x < 10)
                return true;
            int n = x;
            int m = 0;
            while (n > 0) {
                int dig = n % 10;
                m = m * 10 + dig;
                n /= 10;
            }
            return x == m;
        }
};

int main(void)
{
    int x = 11;
    cout << "Is " << x << " a palindrome number?" << Solution().isPalindrome(x) << endl;
    return 0;
}
