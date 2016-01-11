#include <iostream>
#include <map>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        assert(secret.size() == guess.size());
        map<char, int> m;
        int bulls = 0, cows = 0;
        for (string::size_type i = 0, iend = guess.size(); i < iend; ++i) {
            if (guess[i] == secret[i]) {
                ++bulls;
            } else
                ++m[secret[i]];
        }
        for (string::size_type i = 0, iend = guess.size(); i < iend; ++i) {
            if (guess[i] != secret[i] && m[guess[i]]) {
                ++cows;
                --m[guess[i]];
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main(void)
{
    Solution s;
    assert(s.getHint("1807", "7810") == "1A3B");
    assert(s.getHint("1123", "0111") == "1A1B");
    assert(s.getHint("1122", "1222") == "3A0B");
    return 0;
}
