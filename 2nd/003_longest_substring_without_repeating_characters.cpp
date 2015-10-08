#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        if (s.empty())
            return ret;
        map<char, string::size_type> dict;
        for (string::size_type left = 0, right = 0, iend = s.size(); right < iend; ++right) {
            if (dict[s[right]]) {
                string::size_type lend = dict[s[right]];
                while (left < lend)
                    dict.erase(s[left++]);
            }
            dict[s[right]] = right+1;
            if (right-left+1 > ret)
                ret = right-left+1;
        }
        return ret;
    }
};

int main(void)
{
    cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}
