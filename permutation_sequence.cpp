#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        for (int i = 1; i <= n; ++i)
            ret.push_back(i+'0');
        while (k > 0) {
            ret = nextPermutation(ret);
            cout << ret << endl;
            --k;
        }
        return ret;
    }
    string nextPermutation(string str) {
        if (str.empty())
            return str;
        string::size_type a(0), b(0);
        for (string::size_type i = 0; i+1 < str.size(); ++i) {
            if (str[i] < str[i+1]) {
                a = i;
            }
        }
        for (string::size_type i = a+1; i < str.size(); ++i) {
            if (str[i] > str[a])
                b = i;
        }
        swap(str[a], str[b]);
        sort(str.begin()+a+1, str.end());
        return str;
    }
};

int main(void)
{
    cout << Solution().getPermutation(3, 6) << endl;
    return 0;
}
