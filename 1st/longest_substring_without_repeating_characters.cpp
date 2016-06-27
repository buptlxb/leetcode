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
       map<char, string::size_type> m;
       int cur = 0;
       int left = 0;
       for (string::size_type i = 0, isize = s.size(); i < isize; ++i) {
           pair<map<char, string::size_type>::iterator, bool> p = m.insert(make_pair(s[i], i));
           if (p.second)
               ++cur;
           else {
               if (cur > ret)
                   ret = cur;
               while (left <= p.first->second) {
                   m.erase(s[left]);
                   left++;
               }
               m.insert(make_pair(s[i], i));
               cur = i - left + 1;
           }
       }
       if (cur > ret)
           ret = cur;
       return ret;
    }
};

int main(void)
{
    string s("b");
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}
