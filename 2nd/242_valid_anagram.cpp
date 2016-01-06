#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main(void)
{
    Solution s;
    assert(s.isAnagram("anagram", "nagaram"));
    assert(!s.isAnagram("rat", "car"));
    return 0;
}
