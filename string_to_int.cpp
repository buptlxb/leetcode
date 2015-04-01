#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
    public:
        int atoi(string str) {
            int sign = 0;
            int ret = 0;
            int started = 0;
            for (string::iterator iter = str.begin(); iter != str.end(); iter++) {
                if (isspace(*iter))
                    if (started)
                        break;
                    else
                        continue;
                started = 1;
                if (*iter == '+' && !sign) {
                    sign = 1;
                    continue;
                }
                if (*iter == '-' && !sign){
                    sign = -1;
                    started = 1;
                    continue;
                }
                if (sign && (*iter == '-' || *iter == '+'))
                    break;
                if (*iter > '9' || *iter < '0')
                    break;
                int ch = *iter - 48;
                if (ret > (2147483647 - ch)/10)
                    if (sign == -1)
                        return -2147483648;
                    else 
                        return 2147483647;
                ret = ret * 10 + ch;
            }
            return sign >= 0 ? ret : -ret;
        }
};

int main(void)
{
    //string str = "    \t    +-2147483647ba";
    string str = "   + 123";
    cout << Solution().atoi(str) << endl;
}
