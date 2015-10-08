#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        map<string, vector<string> > m;
        for (vector<string>::iterator i = strs.begin(), iend = strs.end(); i != iend; ++i) {
            string tmp(*i);
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(*i);
        }
        vector<vector<string> > ret;
        for (map<string, vector<string> >::iterator i = m.begin(), iend = m.end(); i != iend; ++i) {
            ret.push_back(i->second);
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
