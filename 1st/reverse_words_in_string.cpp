#include <iostream>
#include <string>

using namespace std;

class Solution {
    public :
        void reverseWords(string &s) {
            int start = s.length()-1;
            while (start >= 0 && s[start] == ' ')
                start--;
            if (start < 0) {
                s.clear();
                return;
            }
            
            size_t ret = string::npos;
            string rev;
            while ((ret = s.rfind(' ', start)) != string::npos) {
                rev.append(s.substr(ret+1, start-ret));
                rev.push_back(' ');
                start = ret-1;
                while (start >= 0 && s[start] == ' ')
                    start--;
                if (start < 0)
                    break;
            }
            if (start >= 0) {
                rev.append(s.substr(0, start+1));
            } else {
                rev.erase(rev.length()-1);
            }
            s = rev;
        }
};

int main(void)
{
    Solution s;
    string str("1          ");
    s.reverseWords(str);
    cout << str << endl;
    return 0;
}
