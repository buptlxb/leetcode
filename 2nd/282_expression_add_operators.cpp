#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        addOperators(num, target, 0, 0, "", ret);
        return ret;
    }
    void addOperators(string num, int target, long long cur, long long diff, string str, vector<string> &ret) {
        if (num.size() == 0 && cur == target) {
            ret.push_back(str);
            return;
        }
        for (string::iterator first = num.begin(), i = first, iend = num.end(); i != iend; ++i) {
            string next = string(first, i+1);
            string rest = string(i+1, iend);
            if (next.size() > 1 && *first == '0')
                break;
            if (str.size()) {
                addOperators(rest, target, cur + stoll(next), stoll(next), str + "+" + next, ret);
                addOperators(rest, target, cur - stoll(next), -stoll(next), str + "-" + next, ret);
                addOperators(rest, target, (cur-diff) + diff*stoll(next), diff*stoll(next), str + "*" + next, ret);
            } else {
                addOperators(rest, target, stoll(next), stoll(next), next, ret);
            }
        }
    }
};

int main(void)
{
    Solution s;
    vector<string> ret = s.addOperators("00", 0);
    for (auto str : ret)
        cout << str << endl;
    return 0;
}
