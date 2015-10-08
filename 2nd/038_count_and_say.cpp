#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string cur("1");
        for (int i = 1; i < n; ++i) {
            ostringstream os;
            char c = cur[0];
            int count = 1;
            for (int i = 1, iend = cur.size(); i < iend; ++i) {
                if (c == cur[i])
                    ++count;
                else {
                    os << count << c;
                    count = 1;
                    c = cur[i];
                }
            }
            os << count << c;
            cur = os.str();
        }
        return cur;
    }
};

int main(void)
{
    cout << Solution().countAndSay(9) << endl;
    return 0;
}
