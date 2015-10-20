#include <iostream>
#include <string>
#include <cassert>
#include <map>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size()+s2.size() != s3.size())
            return false;
        map<pair<sz_t, sz_t>, bool> tracks;
        return isInterleave(s1, s2, s3, 0, 0, 0, tracks);
    }
    bool isInterleave(string s1, string s2, string s3, sz_t a, sz_t b, sz_t c, map<pair<sz_t, sz_t>, bool> &tracks) {
        pair<sz_t, sz_t> p(a, b);
        if (tracks[p])
            return false;
        if (a == s1.size() && b == s2.size() && c == s3.size())
            return true;
        if (a < s1.size() && s1[a] == s3[c] && isInterleave(s1, s2, s3, a+1, b, c+1, tracks))
            return true;
        if (b < s2.size() && s2[b] == s3[c] && isInterleave(s1, s2, s3, a, b+1, c+1, tracks))
            return true;
        tracks[p] = true;
        return false;
    }
};

int main(void)
{
    Solution s;
    assert(s.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    assert(!s.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    assert(!s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
                "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
                "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbb\
                ababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"
                )
          );
    return 0;
}
