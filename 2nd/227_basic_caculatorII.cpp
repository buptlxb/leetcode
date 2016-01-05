#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;
        for (string::iterator i = s.begin(), iend = s.end(); i != iend; ++i) {
            switch (*i) {
                case '+': case '-': case '*': case '/':
                    while (!ops.empty() && less(*i, ops.top())) {
                        cal(nums, ops.top());
                        ops.pop();
                    }
                    ops.push(*i);
                case ' ':
                    break;
                default:
                    nums.push(getNum(i, iend));
            }
        }
        while (!ops.empty()) {
            cal(nums, ops.top());
            ops.pop();
        }
        return nums.top();
    }
    bool less(char lhs, char rhs) {
        if (rhs == '*' || rhs == '/' || lhs == '+' || lhs == '-')
            return true;
        return false;
    }
    void cal(stack<int> &nums, char op) {
        int rhs = nums.top();
        nums.pop();
        int lhs = nums.top();
        nums.pop();
        switch (op) {
            case '+':
                nums.push(lhs + rhs);
                break;
            case '-':
                nums.push(lhs - rhs);
                break;
            case '*':
                nums.push(lhs * rhs);
                break;
            case '/':
                nums.push(lhs / rhs);
                break;
            default:
                assert(false);
        }
    }
    int getNum(string::iterator &first, string::iterator last) {
        int ret = 0;
        for (; first != last && isdigit(*first); ++first) {
            ret = 10 * ret + *first - '0';
        }
        --first;
        return ret;
    }
};

int main(void)
{
    Solution s;
    assert(7 == s.calculate("3+2*2"));
    assert(1 == s.calculate(" 3/2 "));
    assert(5 == s.calculate(" 3+5 / 2 "));
    cout << s.calculate("100000000/1/2/3/4/5/6/7/8/9/10") << endl;
    return 0;
}
