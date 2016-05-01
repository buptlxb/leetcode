#include <iostream>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    bool isValidSerialization(string preorder) {
        int diff = 1;
        for (sz_t i = 0, start = 0, iend = preorder.size(); ; ++i) {
            if (i == iend || preorder[i] == ',') {
                if (--diff < 0)
                    return false;
                if (start+1 != i || preorder[start] != '#')
                    diff += 2;
                start = i+1;
                if (i == iend)
                    break;
            }
        }
        return diff == 0;
    }
};

int main(void)
{
    Solution s;
    cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << s.isValidSerialization("9,#,#,1") << endl;
    return 0;
}
