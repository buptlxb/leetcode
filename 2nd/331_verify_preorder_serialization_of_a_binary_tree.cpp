#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.size() == 0)
            return true;
        preorder.push_back(',');
        stack<char> s;
        char p;
        for (auto c : preorder) {
            if (c == ',') {
                if (p == '#') {
                    while (!s.empty() && s.top() == '#') {
                        s.pop();
                        if (s.empty() || s.top() == '#')
                            return false;
                        else
                            s.pop();
                    }
                }
                s.push(p);
            } else {
                p = c;
            }
        }
        return s.size() == 1 && s.top() == '#';
    }
};

int main(void)
{
    Solution s;
    cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    return 0;
}
