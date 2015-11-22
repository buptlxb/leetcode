#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int cur_sum = 0;
        int start = -1;
        for (int i = 0, iend = gas.size(); i < iend; ++i) {
            sum += gas[i] - cost[i];
            cur_sum += gas[i] - cost[i];
            if (cur_sum < 0) {
                start = i;
                cur_sum = 0;
            }
        }
        if (sum < 0)
            return -1;
        return start+1;
    }
};

int main(void)
{
    return 0;
}
