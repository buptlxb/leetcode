#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0;
        int cur_sum = 0;
        int start = -1;
        for (vector<int>::size_type i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            cur_sum += gas[i] - cost[i];
            if (cur_sum < 0) {
                cur_sum = 0;
                start = i;
            }
        }
        if (sum < 0)
            return -1;
        return start + 1;
    }
};

int main(void)
{
    vector<int> gas;
    gas.push_back(1);
    gas.push_back(2);
    gas.push_back(3);
    vector<int> cost;
    cost.push_back(3);
    cost.push_back(2);
    cost.push_back(1);
    cout << Solution().canCompleteCircuit(gas, cost) << endl;
}
