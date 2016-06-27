#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if (!s.size() || words.empty() || s.size() < words.front().size())
            return ret;

        map<string, int> m, n;
        for (vector<string>::const_iterator i = words.begin(), iend = words.end(); i != iend; ++i) {
            ++m[*i];
        }
        for (string::size_type i = 0, iend = words.front().size(); i < iend; ++i) {
            int count = words.size();
            for (string::size_type index = i, j = i, jend = s.size()-iend; j <= jend; j += iend) {
                map<string, int>::iterator iter = m.find(s.substr(j, iend));
                if (iter == m.end()) {
                    index = j + iend;
                    n.clear();
                    count = words.size();
                } else {
                    ++n[iter->first];
                    if (n[iter->first] <= iter->second) {
                        if (!--count) {
                            ret.push_back(index);
                            --n[s.substr(index, iend)];
                            ++count;
                            index += iend;
                        }
                    } else {
                        while (n[iter->first] > iter->second) {
                            string tmp = s.substr(index, iend);
                            --n[tmp];
                            if (n[tmp] < m[tmp])
                                ++count;
                            index += iend;
                        }
                    }
                }
            }
            n.clear();
        }
        return ret;
    }
};

int main(void)
{
    string s;
    getline(cin, s);
    string words;
    getline(cin, words);
    vector<string> vec;
    istringstream is(words);
    string tmp;
    while (is >> tmp) {
        vec.push_back(tmp);
    }
    vector<int> ret = Solution().findSubstring(s, vec);
    cout << "[ ";
    for (vector<int>::const_iterator i = ret.begin(), iend = ret.end(); i != iend; ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;
    return 0;
}
