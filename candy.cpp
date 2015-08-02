#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cstdlib>

using namespace std;

class Solution {

public:

    typedef vector<int>::size_type s_t;
    int candy(vector<int>& ratings) {
        int ret(ratings.size());
        if (ret < 2)
            return ret;
        vector<int> candies(ratings.size(), 1);
        for (s_t i = 1, iend = ratings.size(); i < iend; ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] += candies[i-1];
            }
        }
        for (s_t i = ratings.size(); i > 1; --i) {
            if (ratings[i-1] < ratings[i-2]) {
                candies[i-2] = max(candies[i-1] + 1, candies[i-2]);
            }
        }
        ret = 0;
        copy(candies.begin(), candies.end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
        return accumulate(candies.begin(), candies.end(), ret);
    }

};

int main(void)
{
    //int array[] = {1, 3, 2, 1, 4, 2, 3, 2, 1};
    int array[] = {4, 2, 3, 4, 1};
    vector<int> ratings(array, array+sizeof(array)/sizeof(int));
    cout << Solution().candy(ratings) << endl;
    return 0;
}
