#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int maxProduct(vector<string>& words) {
        if (words.size() < 2)
            return 0;
        vector<int> hash(words.size());
        transform(words.begin(), words.end(), hash.begin(), bind1st(mem_fun(&Solution::s2i), this));
        sz_t ret = 0;
        for (sz_t i = 0, iend = words.size(); i < iend; ++i) {
            for (sz_t j = i+1, jend = iend; j < jend; ++j) {
                if (hash[j] & hash[i])
                    continue;
                ret = max(ret, words[i].size() * words[j].size());
            }
        }
        return ret;
    }
    int s2i(string s) {
        int ret = 0;
        for (auto c : s) {
            ret |= 1 << (c -'a');
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    vector<string> words{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << s.maxProduct(words) << endl;
    vector<string> words1{"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    cout << s.maxProduct(words1) << endl;
    vector<string> words2{"a", "aa", "aaa", "aaaa"};
    cout << s.maxProduct(words2) << endl;
    return 0;
}
