#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int main(void)
{
    Solution s;
    cout << s.bulbSwitch(99999) << endl;
    return 0;
}
