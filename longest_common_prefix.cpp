#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret;
        if (strs.empty())
            return ret;
        string str = strs.front();
        if (strs.size() == 1)
            return str;
        string::size_type i = 0;
        while (i < str.size()) {
            vector<string>::iterator iter = strs.begin()+1;
            for (;iter != strs.end(); iter++) {
                if (i >= iter->size() || str[i] != (*iter)[i])
                    break;
            }
            if (iter != strs.end())
                break;
            ret.push_back(str[i]);
            i++;
        }
        return ret;
    }
};

int main(void)
{
    vector<string> vec;
    vec.push_back("123abc");
    vec.push_back("123adc");
    vec.push_back("12");

    cout << Solution().longestCommonPrefix(vec) << endl;
    return 0;
}
