#include <iostream>

using namespace std;

class Solution {
    public:
        int strStr(const char *haystack, const char *needle) {
            if (*haystack == '\0' && *needle == '\0')
                return 0;
            int index = -1;
            while (*haystack) {
                index++;
                const char *i = needle;
                while (*i && *haystack == *i) {
                    haystack++;
                    i++;
                }
                if (*i == '\0')
                    return index;
                haystack = haystack - i + needle + 1;
            }
        }
};

int main(void)
{
    const char *haystack = "haystack";
    const char *needle = "sta";
    cout << Solution().strStr(haystack, needle) << endl;
    return 0;
}
