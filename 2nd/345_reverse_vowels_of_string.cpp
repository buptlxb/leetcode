#include <iostream>

using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s) {
        string::size_type left = 0, right = s.size();
        while (left < right) {
            while (left < right && !isVowel(s[left]))
                ++left;
            while (left < right && !isVowel(s[right-1]))
                --right;
            if (left < right)
                swap(s[left++], s[--right]);
        }
        return s;
    }
};

int main(void)
{
    cout << Solution().reverseVowels("hello") << endl;
    return 0;
}
