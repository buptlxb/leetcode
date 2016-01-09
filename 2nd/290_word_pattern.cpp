#include <iostream>
#include <map>
#include <sstream>
#include <cassert>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream is(str);
        map<char, string> m;
        map<string, char> n;
        string tmp;
        string::iterator i = pattern.begin();
        while (is >> tmp) {
            if (m[*i].size() && m[*i] != tmp || n[tmp] && n[tmp]  != *i)
                return false;
            m[*i] = tmp;
            n[tmp] = *i++;
        }
        return i == pattern.end();
    }
};

int main(void)
{
    Solution s;
    assert(s.wordPattern("abba", "dog cat cat dog"));
    assert(!s.wordPattern("abba", "dog cat cat fish"));
    assert(!s.wordPattern("aaaa", "dog cat cat dog"));
    assert(!s.wordPattern("abba", "dog dog dog dog"));
    assert(!s.wordPattern("jquery", "jqyery"));
    return 0;
}
