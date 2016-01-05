#include <iostream>
#include <functional>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        string::iterator first = s.begin();
        return calculate(first, s.end());
    }
    int calculate(string::iterator &first, string::iterator last) {
        int ret = 0, cur_op = 0;
        function<int(int, int)> ops[] = {plus<int>(), minus<int>()};
        while (first != last) {
            switch (*first) {
                case '(':
                    ret = ops[cur_op]((int)ret, calculate(++first, last));
                    break;
                case '+':
                    ++first;
                    cur_op = 0;
                    break;
                case '-':
                    ++first;
                    cur_op = 1;
                    break;
                case ')':
                    ++first;
                    return ret;
                case ' ':
                    ++first;
                    break;
                default:
                    ret = ops[cur_op]((int)ret, getNum(first, last));
            }
        }
        return ret;
    }
    int getNum(string::iterator &first, string::iterator last) {
        int ret = 0;
        for (; first != last && isdigit(*first); ++first)
            ret = ret * 10 + *first - '0';
        return ret;
    }
};

int main(void)
{
    Solution s;
    cout << s.calculate("1 + 1") << endl;
    cout << s.calculate(" 2-1 + 2 ") << endl;
    cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    return 0;
}
