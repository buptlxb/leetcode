#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            if (n == 1)
                return "1";
            string ret = "11";
            int i = 2;
            while (i < n) {
                string tmp;
                char cur = ret[0];
                int count = 1;
                for (string::iterator iter = ret.begin()+1; iter != ret.end(); iter++) {
                    if (cur == *iter)
                        count++;
                    else {
                        tmp.push_back(count+0x30);
                        tmp.push_back(cur);
                        cur = *iter;
                        count = 1;
                    }
                }
                tmp.push_back(count+0x30);
                tmp.push_back(cur);
                ret = tmp;
                i++;
            }
            return ret;
        }
};

int main(void)
{
    cout << Solution().countAndSay(6) << endl;
    return 0;
}
