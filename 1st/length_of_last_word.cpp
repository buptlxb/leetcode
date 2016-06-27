#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int ret = 0;
        int cur = 0;
        while (*s) {
            if (*s == ' ') {
                ret = cur ? cur : ret;
                cur = 0;
            } else {
                cur++;
            }
            s++;
        }
        ret = cur ? cur : ret;
        return ret;
    }
};

int main(void)
{
    const char *str = " ";
    cout << Solution().lengthOfLastWord(str) << endl;
    return 0;
}
