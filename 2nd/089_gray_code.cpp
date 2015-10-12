#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        grayCode(n, ret);
        return ret;
    }   
    void grayCode(int n, vector<int> &ret) {
        if (n == 0) {
            ret.push_back(0);
        } else {
            grayCode(n-1, ret);
            ret.reserve(ret.size()<<1);
            transform(ret.rbegin(), ret.rend(), back_inserter(ret), bind1st(plus<int>(), 1<<(n-1)));
        }   
    }   
};

ostream & operator<< (ostream &os, const vector<int> &vec) {
    if (vec.empty()) {
        os << "[]";
    } else {
        os << "[" << vec.front();
        for (vector<int>::const_iterator i = vec.begin()+1, iend = vec.end(); i != iend; ++i) {
            os << ", " << *i;
        }
        os << "]";
    }
    return os;
}

int main(void)
{
    cout << Solution().grayCode(3) << endl;
    return 0;
}
