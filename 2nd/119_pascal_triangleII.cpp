#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > ret(2, vector<int>(rowIndex+1, 1));
        int index = 0;
        for (int i = 1; i < rowIndex+1; ++i) {
            for (int j = 1; j <= i; ++j) {
                ret[1-index][j] = ret[index][j] + ret[index][j-1];
            }
            index = 1 - index;
        }
        return ret[1-index];
    }                                                                                                                                        
};

int main(void)
{
    return 0;
}
