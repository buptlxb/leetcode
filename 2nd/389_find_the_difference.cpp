#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> dict;
        for (auto c : s)
            ++dict[c];
        for (auto c : t) {
            if (dict[c]-- == 0)
                return c;
        }
        return 0;
    }
};

int main(void)
{
    return 0;
}
