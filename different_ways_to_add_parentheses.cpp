#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

class Solution {
public:
    typedef string::size_type s_t;
    vector<int> diffWaysToCompute(string input) {
        bool pure = true;
        vector<int> ret;
        for (s_t i = 0; i < input.size(); ++i) {
            if (!isdigit(input[i])) {
                pure = false;
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for (s_t k = 0; k < left.size(); ++k) {
                    for (s_t j = 0; j < right.size(); ++j) {
                        ret.push_back(compute(left[k], right[j], input[i]));
                    }
                }
            }
        }
        if (pure) {
            istringstream is(input);
            int tmp;
            is >> tmp;
            ret.push_back(tmp);
        }
        return ret;
    }
    int compute(int lhs, int rhs, char op) {
        switch (op) {
            case '-':
                return lhs - rhs;
            case '+':
                return lhs + rhs;
            case '*':
                return lhs * rhs;
            default:
                cerr << "Unknown operator:" << op << endl;
                return -1;
        }
    }
};

int main(void)
{
    vector<int> ret = Solution().diffWaysToCompute("2*3-4*5");
    copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    return 0;
}
