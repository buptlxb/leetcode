#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
        string::size_type last = 0;
        for (string::size_type i = 0, iend = path.size(); i < iend; ++i) {
            if (path[i] == '/') {
                if (i != last) {
                    string tmp = path.substr(last, i-last);
                    simplify(tmp, s);
                }
                last = i+1;
            }
        }
        if (last != path.size()) {
            string tmp = path.substr(last, path.size()-last);
            simplify(tmp, s);
        }
        ostringstream os;
        for (vector<string>::iterator i = s.begin(), iend = s.end(); i != iend; ++i) {
            os << "/" << *i;
        }
        return os.str() == "" ? "/" : os.str();
    }
    void simplify(string &str, vector<string> &s) {
        if (str == ".")
            ;
        else if (str == "..") {
            if (!s.empty())
                s.pop_back();
        } else
            s.push_back(str);
    }
};

int main(void)
{
    Solution s;
    assert(s.simplifyPath("/home/") == "/home");
    assert(s.simplifyPath("/a/./b/../../c/") == "/c");
    assert(s.simplifyPath("///") == "/");
    assert(s.simplifyPath("/../") == "/");
    assert(s.simplifyPath("/...") == "/...");
    return 0;
}
