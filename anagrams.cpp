#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> ret;
        map<string, vector<string>::iterator> m;
        for (vector<string>::iterator i = strs.begin(), iend = strs.end(); i != iend; ++i) {
            string tmp = *i;
            sort(tmp.begin(), tmp.end());
            map<string, vector<string>::iterator>::iterator found = m.find(tmp);
            if (found != m.end()) {
                ret.push_back(*i);
                if (found->second != strs.end()) {
                    ret.push_back(*found->second);
                    m[tmp] = strs.end();
                }
            } else
                m[tmp] = i;
        }
        return ret;
    }
};

int main(void)
{
    vector<string> strs;
    strs.push_back("and");
    strs.push_back("dan");
    vector<string> ret = Solution().anagrams(strs);
    for (vector<string>::iterator i = ret.begin(), iend = ret.end(); i != iend; ++i) {
        cout << *i << endl;
    }
    return 0;
}
