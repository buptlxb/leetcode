#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        ret.reserve(n);
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            ret.push_back(cur);
            if (cur * 10 <= n)
                cur *= 10;
            else if (cur % 10 != 9 && cur + 1 <= n)
                cur += 1;
            else {
                while (cur / 10 % 10 == 9)
                    cur /= 10;
                cur = cur / 10 + 1;
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    for (auto x : s.lexicalOrder(13))
        cout << x << endl;
    return 0;
}
