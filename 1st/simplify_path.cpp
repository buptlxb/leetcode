#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> q;
        string::size_type i = 1, iend = path.size();
        while (i < iend) {
            string tmp;
            while (i < iend && path[i] != '/')
                tmp.push_back(path[i++]);
            if (tmp.empty() || tmp == ".")
                ;
            else if (tmp == "..") {
                if (!q.empty())
                    q.pop_back();
            } else {
                q.push_back(tmp);
            }
            ++i;
        }
        string ret;
        for (vector<string>::iterator i = q.begin(), iend = q.end(); i != iend; ++i) {
            ret.append("/");
            ret.append(*i);
        }
        if (ret.empty())
            ret.append("/");
        return ret;
    }
};

int main(void)
{
    string path = "/home/foo/.ssh/../../../../.ssh2/authorized_keys/";
    cout << Solution().simplifyPath(path) << endl;
    return 0;
}
