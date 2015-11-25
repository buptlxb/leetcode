#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cstdint>

using namespace std;

class Solution {
public:
    typedef int64_t (Solution::*Operator)(int64_t, int64_t);
    int evalRPN(vector<string>& tokens) {
        stack<int64_t> s;
        string operators("+-*/");
        Operator ops[] {&Solution::add, &Solution::sub, &Solution::mul, &Solution::div};
        int idx;
        for (auto token : tokens) {
            if (string::npos == (idx = operators.find(token))) {
                int64_t rhs = s.top();
                s.pop();
                int64_t lhs = s.top();
                s.pop();
                s.push((this->*ops[idx])(lhs, rhs));
            } else {
                s.push(atoll(token.c_str()));
            }
        }
        return s.top();
    }
    int64_t add(int64_t lhs, int64_t rhs) {
        return lhs + rhs;
    }
    int64_t sub(int64_t lhs, int64_t rhs) {
        return lhs - rhs;
    }
    int64_t mul(int64_t lhs, int64_t rhs) {
        return lhs * rhs;
    }
    int64_t div(int64_t lhs, int64_t rhs) {
        return lhs / rhs;
    }
};

int main(void)
{
    return 0;
}
