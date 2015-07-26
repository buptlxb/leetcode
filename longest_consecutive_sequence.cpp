#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdlib>

using namespace std;

class Solution {

public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for (auto i = nums.begin(), iend = nums.end(); i != iend; ++i) {
            us.insert(*i);
        }
        int ret = 0;
        for (auto i = nums.begin(), iend = nums.end(); i != iend; ++i) {
            ret = max(ret, bound(us, *i, true) + bound(us, *i+1, false));
        }
        return ret;
    }
    int bound(unordered_set<int> &us, int num, bool direct) {
        int count = 0;
        for (auto i = us.find(num); i != us.end(); i = us.find(num)) {
            us.erase(i);
            if (direct)
                --num;
            else
                ++num;
            ++count;
        }
        return count;
    }
};

int main(void)
{
    int array[] = {100, 4, 200, 1, 3, 2};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    cout << Solution().longestConsecutive(nums) << endl;
    return 0;
}
