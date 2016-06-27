#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::vector;

class Solution {
    public:

        int rob(vector<int> &num) {
            if (num.size() == 0)
                return 0;
            if (num.size() == 1)
                return num.front();
            if (num.size() == 2)
                return num[0] > num[1] ? num[0] : num[1];
            int a = num[0];
            int b = num[0] > num[1] ? num[0] : num[1];
            for (vector<int>::size_type i = 2; i < num.size(); i++) {
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
