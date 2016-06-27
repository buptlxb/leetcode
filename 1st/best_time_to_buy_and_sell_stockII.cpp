#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (vector<int>::size_type i = 1, isize = prices.size(); i < isize; ++i) {
            if (prices[i] > prices[i-1])
                ret += prices[i] - prices[i-1];
        }
        return ret;
    }
};

int main(void)
{
    int array[] = {1, 2, 3, 4};
    vector<int> vec(array, array+sizeof(array)/sizeof(array[0]));
    cout << Solution().maxProfit(vec) << endl;

}
