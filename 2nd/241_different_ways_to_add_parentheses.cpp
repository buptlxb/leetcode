#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef string::iterator Iter;
    vector<int> diffWaysToCompute(string input) {
        return diffWaysToCompute(input.begin(), input.end());
    }
    vector<int> diffWaysToCompute(Iter first, Iter last) {
        vector<int> ret;
        bool isPrimitive = true;
        for (Iter i = first; i != last; ++i) {
            if (isdigit(*i))
                continue;
            isPrimitive = false;
            vector<int> left = diffWaysToCompute(first, i);
            vector<int> right = diffWaysToCompute(i+1, last);
            for (auto lhs : left)
                for (auto rhs : right)
                    ret.push_back(compute(lhs, rhs, *i));
        }
        if (isPrimitive) {
            istringstream is(string(first, last));
            int tmp;
            is >> tmp;
            ret.push_back(tmp);
        }
        return ret;
    }
    int compute(int lhs, int rhs, char c) {
        switch (c) {
            case '+':
                return lhs + rhs;
            case '-':
                return lhs - rhs;
            case '*':
                return lhs * rhs;
            default:
                assert(false);
        }
        return 0;
    }
};

int main(void)
{
    Solution s;
    vector<int> res{-34, -14, -10, -10, 10};
    vector<int> ret = s.diffWaysToCompute("2*3-4*5");
    sort(ret.begin(), ret.end());
    assert(equal(res.begin(), res.end(), ret.begin()));
    return 0;
}
