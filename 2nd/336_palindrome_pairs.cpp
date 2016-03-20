#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > ret;
        map<string, sz_t> m;
        for (sz_t i = 0, iend = words.size(); i != iend; ++i)
            m[words[i]] = i;
        map<string, sz_t>::iterator found;
        for (sz_t i = 0, iend= words.size(); i != iend; ++i) {
            if (isPalindrome(words[i]) && (found = m.find("")) != m.end() && i != found->second) {
                ret.push_back(vector<int>{static_cast<int>(found->second), static_cast<int>(i)});
                ret.push_back(vector<int>{static_cast<int>(i), static_cast<int>(found->second)});
            }
            string word = words[i];
            reverse(word.begin(), word.end());
            if ((found = m.find(word)) != m.end() && i != found->second) {
                ret.push_back(vector<int>{static_cast<int>(found->second), static_cast<int>(i)});
            }
            for (sz_t j = 1, jend = words[i].size(); j < jend; ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                reverse(right.begin(), right.end());
                reverse(left.begin(), left.end());
                if (isPalindrome(left) && (found = m.find(right)) != m.end() && i != found->second)
                    ret.push_back(vector<int>{static_cast<int>(found->second), static_cast<int>(i)});
                if (isPalindrome(right) && (found = m.find(left)) != m.end() && i != found->second)
                    ret.push_back(vector<int>{static_cast<int>(i), static_cast<int>(found->second)});
            }
        }
        return ret;
    }
    bool isPalindrome(const string &s) {
        for (sz_t i = 0, iend = s.size(); i < iend; ++i, --iend) {
            if (s[i] != s[iend-1])
                return false;
        }
        return true;
    }
};

int main(void)
{
    //vector<string> words{"abcd", "dcba", "lls", "s", "sssll"};
    vector<string> words{"a", ""};
    vector<vector<int> > ret = Solution().palindromePairs(words);
    for (auto p : ret) {
        cout<< p[0] << ", " << p[1] << endl;
    }
    return 0;
}
