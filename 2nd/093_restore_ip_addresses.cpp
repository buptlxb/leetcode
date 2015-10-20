#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret, tmp;
        restoreIpAddresses(s, 0, tmp, ret);
        return ret;
    }
    void restoreIpAddresses(string s, string::size_type index, vector<string> &tmp, vector<string> &ret) {
        if (tmp.size() == 4) {
            if (index == s.size())
                ret.push_back(join(tmp));
            return;
        }
        int cnt = 0;
        for (string::size_type i = index, iend = s.size(); i < iend; ++i) {
            cnt = cnt * 10 + s[i] - '0';
            if (cnt > 255)
                break;
            tmp.push_back(s.substr(index, i-index+1));
            restoreIpAddresses(s, i+1, tmp, ret);
            tmp.pop_back();
            if (s[index] == '0')
                break;
        }
    }
    string join(vector<string> vec, string delimiter = ".") {
        ostringstream os;
        if (vec.empty())
            return os.str();
        os << vec.front();
        for (vector<string>::iterator i = vec.begin()+1, iend = vec.end(); i != iend; ++i) {
            os << delimiter << *i;
        }
        return os.str();
    }
};

int main(void)
{
    return 0;
}
