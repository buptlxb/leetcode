#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

class Solution {
public:
    typedef string::size_type s_t;
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> ret;
        if (s.size() <= 10)
            return vector<string>();
        set<long long> table;
        for (s_t i = 10, iend = s.size(); i <= iend; ++i) {
            long long hash = 0;
            int base = 1;
            for (s_t j = i-10; j < i; ++j) {
                switch (s[j]) {
                    case 'A':
                        break;
                    case 'C':
                        hash += 1 * base;
                        break;
                    case 'G':
                        hash += 2 * base;
                        break;
                    case 'T':
                        hash += 3 * base;
                        break;
                    default:
                        cout << "error" << endl;
                }
                base *= 4;
            }
            pair<set<long long>::iterator, bool> p = table.insert(hash);
            if (!p.second) {
                ret.insert(s.substr(i-10, 10));
            }
        }
        return vector<string>(ret.begin(), ret.end());
    }
};

int main(void)
{
    //vector<string> ret = Solution().findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    vector<string> ret = Solution().findRepeatedDnaSequences("AAAAAAAAAAA");
    copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}
