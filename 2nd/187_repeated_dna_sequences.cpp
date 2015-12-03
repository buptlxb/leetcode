#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> um;
        vector<string> ret;
        if (s.size() < 11)
            return ret;
        for (string::iterator i = s.begin(), iend = s.end()-9; i < iend; ++i) {
            string cur(i, i+10);
            if (++um[cur] == 2)
                ret.push_back(cur);
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
