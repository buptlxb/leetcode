#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int candy(vector<int>& ratings) {
        if (ratings.empty())
            return 0;
        vector<int> candies(ratings.size(), 1);
        for (sz_t i = 1, iend = ratings.size(); i < iend; ++i) {
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }
        for (sz_t i = ratings.size()-1; i > 0; --i) {
            if (ratings[i] < ratings[i-1] && candies[i-1] <= candies[i])
                candies[i-1] = candies[i] + 1;
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main(void)
{
    return 0;
}
