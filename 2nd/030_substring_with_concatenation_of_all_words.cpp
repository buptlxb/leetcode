#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> indices;
        if (words.empty())
            return indices;
        sz_t word_len = words.front().size();
        sz_t len = words.size() * word_len;
        if (s.size() < len)
            return indices;
        map<string, int> dict;
        for (sz_t i = 0, iend = words.size(); i < iend; ++i) {
            ++dict[words[i]];
        }
        for (sz_t i = 0, iend = s.size()-len+1; i < iend; ++i) {
            map<string, int> tmp(dict);
            sz_t count = 0;
            for (sz_t j = 0, jend = len; j < jend; j+=word_len) {
                if (--tmp[s.substr(i+j, word_len)] < 0)
                    break;
                ++count;
            }
            if (count == words.size())
                indices.push_back(i);
        }
        return indices;
    }
};

int main(void)
{
    string s = "barfoothefoobarman";
    string a[] = {"foo", "bar"};
    vector<string> words(a, a+2);
    auto indices = Solution().findSubstring(s, words);
    for (auto index : indices)
        cout << index << endl;
    return 0;
}
