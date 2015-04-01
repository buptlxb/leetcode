#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
        int majorityElement(vector<int> &num) {
            int me = num.front();
            int count = 1;
            for (vector<int>::iterator iter = ++num.begin(); iter != num.end(); iter++) {
                if (me == *iter)
                    count++;
                else
                    count--;
                if (!count) {
                    me = *iter;
                    count = 1;
                }
            }
            return me;
        }
};

int main(void)
{
    vector<int> vec(4, 1);
    vec.push_back(2);
    vec.push_back(3);
    cout << "Majority Element is " << Solution().majorityElement(vec) << endl;
    return 0;
}
