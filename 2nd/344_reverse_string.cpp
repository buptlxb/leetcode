#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        for (string::size_type left = 0, right = s.size(); left < right; ++left, --right)
            swap(s[left], s[right-1]);
        return s;
    }
};

int main(void)
{
    cout << Solution().reverseString("hello") << endl;
    return 0;
}
