#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for (vector<int>::size_type i = 3, iend = x.size(); i < iend; ++i) {
            /*
             *    i-2
             *    ----
             * i-1|  |i-3
             *    ---|->
             *         i 
             */
            if (x[i] >= x[i-2] && x[i-1] <= x[i-3])
                return true;
            /*
             *    i-3
             *    ----
             * i-2|  |i-4
             *    |  ^
             *    |  |i
             *    ---|
             *    i-1
             */
            else if (i > 3 && x[i-3] == x[i-1] && x[i-2] == x[i-4] + x[i])
                return true;
            /*
             *    i-4
             *    ----
             *    |  |i-5
             * i-3|  |<----
             *    |    i  |
             *    |       |i-1
             *    ---------
             *       i-2
             */
            else if (i > 4 && x[i-4] < x[i-2] && x[i-3] <= x[i-5] + x[i-1] && x[i] + x[i-4] >= x[i-2] && x[i-1] <= x[i-3])
                return true;
        }
        return false;
    }
};

int main(void)
{
    return 0;
}
