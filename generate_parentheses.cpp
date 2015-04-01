#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void generate(int left, int right, string str, vector<string>& vec) {
        if (!left && !right) {
            vec.push_back(str);
            return;
        }
        if (left > 0)
            generate(left-1, right, str+"(", vec);
        if (right > 0 && right > left)
            generate(left, right-1, str+")", vec);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        generate(n, n, "", vec);
        return vec;
    }
};

int main(void)
{
    Solution s = Solution();
    vector<string> vec = s.generateParenthesis(3);
    for (vector<string>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << endl;
    return 0;
}
