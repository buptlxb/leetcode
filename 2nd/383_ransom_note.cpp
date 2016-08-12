#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dict;
        for (auto c : magazine)
            ++dict[c];
        for (auto c : ransomNote)
            if (dict[c]-- == 0)
                return false;
        return true;
    }
};

int main(void)
{
    return 0;
}
