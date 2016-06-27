#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty())
            return ret;
        string dict[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper("", digits, ret, dict);
        return ret;
    }
private:
    void helper(string prefix, const string &digits, vector<string> &vec, string dict[]) {
        if (digits.size() == prefix.size())
            vec.push_back(prefix);
        else {
            string cur = dict[digits[prefix.size()] - '0'];
            for (string::size_type i = 0, iend = cur.size(); i < iend; ++i) {
                helper(prefix+cur[i], digits, vec, dict);
            }
        }
    }
};

int main(void)
{
    string digits = "23";
    vector<string> vec = Solution().letterCombinations(digits);
    for (vector<string>::iterator iter = vec.begin(), end = vec.end(); iter != end; ++iter) {
        cout << *iter << endl;
    }
    return 0;
}
