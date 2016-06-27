#include <iostream>

using namespace std;

class Solution {
    public:
        int titleToNumber(string s) {
            int ret = 0;
            for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
                ret = ret * 26 + *iter - 'A' + 1;
            }
            return ret;
        }
};

int main(void)
{
    string s = "AB";
    cout << s << " -> " << Solution().titleToNumber(s) << endl;
}
