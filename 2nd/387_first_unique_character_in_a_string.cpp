#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> dict(26);
        for (auto c : s)
            ++dict[c-'a'];
        for (int i = 0; i < s.size(); ++i)
            if (dict[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};

int main(void)
{
    return 0;
}
