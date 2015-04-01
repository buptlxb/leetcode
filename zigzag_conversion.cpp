#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string convert(string s, int nRows) {
            int len = s.length();
            if (len <= nRows || nRows < 2)
                return s;
            string buf;
            int step = 2*(nRows-1);
            for (int i = 0; i < nRows; i++) {
                for (int j = i; j < len; j = j+step) {
                    buf.append(1, s[j]);
                    if (i > 0 && i < nRows-1 && j+2*(nRows-i-1) < len) {
                        buf.append(1, s[j+2*(nRows-i-1)]);
                    }
                }
            }
            return buf;
        }
};

int main(void)
{
    string s = "rmywpjscjfrhnyakdhiczbjfideaugelvekkpcmyjgfwghijqsoqtxxdacdwkjifpusgweefmmdtvlcmdqeypbdqfimq";
    cout << Solution().convert(s, 87) << endl;
    string s2 = "PAYPALISHIRING";
    cout << Solution().convert(s2, 3) << endl;
    return 0;
}
