#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution {
    public:
        typedef vector<int>::size_type s_t;
        int rob(vector<int> &num) {
            if (num.size() == 0)
                return 0;
            if (num.size() == 1)
                return num.front();
            if (num.size() == 2)
                return max(num[0], num[1]);
            int a = rob(num, 0, num.size()-1);
            int b = rob(num, 1, num.size()-2) + num.back();
            return max(a, b);
        }

        int rob(vector<int> &num, s_t start, s_t end) {
            if (start == end)
                return 0;
            if (end-start == 1)
                return num[start];
            if (end-start == 2)
                return max(num[start], num[start+1]);
            int a = num[start];
            int b = max(num[start], num[start+1]);
            for (vector<int>::size_type i = start+2; i < end; i++) {
                int c = a + num[i]; 
                c = c > b ? c : b;
                a = b;
                b = c;
            }
            return b;
        }
};


int main(void)
{
    vector<int> num;
    num.push_back(1);
    num.push_back(7);
    num.push_back(9);
    num.push_back(4);
    cout << Solution().rob(num) << endl;
    return 0;
}
