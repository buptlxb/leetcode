#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stringstream;
using std::sort;


class Solution {
public:
    static bool cmp(int a, int b) {
        stringstream ab; 
        ab << a << b;
        stringstream ba;
        ba << b << a;
        return ab.str().compare(ba.str()) > 0;
    }

    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), Solution::cmp);
        stringstream buf;
        for (vector<int>::size_type i = 0; i < num.size(); i++) {
            buf << num[i];
        }
        string ret = buf.str();
        string::iterator i = ret.begin();
        while (i != ret.end() && *i == '0') {
            i++;
        }
        if (i == ret.end())
            return string("0");
        return string(i, ret.end());
    }
};

int main(void)
{
    vector<int> num;
    //num.push_back(3);
    //num.push_back(30);
    //num.push_back(34);
    //num.push_back(5);
    //num.push_back(9);
    num.push_back(0);
    num.push_back(0);
    cout << Solution().largestNumber(num) << endl;
    return 0;
}
