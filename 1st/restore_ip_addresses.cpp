#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <cstdlib>

using namespace std;

class Solution {
public:
    typedef string::size_type s_t;
    vector<string> restoreIpAddresses(string s) {
       vector<string> ret;
       vector<string> tmp;
       restoreIpAddresses(s, 0, tmp, ret);
       return ret;
    }
    void restoreIpAddresses(string s, s_t start, vector<string> &tmp, vector<string> &ret) {
        if (tmp.size() == 4 && start == s.size()) {
            ostringstream os;
            os << tmp[0] << "." << tmp[1] << "." << tmp[2] << "." << tmp[3];
            ret.push_back(os.str());
        } else if (tmp.size() != 4 && start != s.size()) {
            string num;
            while (start < s.size()) {
                if (!num.empty() && num[0] == '0')
                    break;
                num.push_back(s[start]);
                if (atoi(num.c_str()) > 255)
                    break;
                tmp.push_back(num);
                restoreIpAddresses(s, start+1, tmp, ret);
                tmp.pop_back();
                ++start;
            }
        }
    }
};

int main(void)
{
    vector<string> ret = Solution().restoreIpAddresses("010010");
    copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, "\n"));
    cout << endl;
    return 0;
}
