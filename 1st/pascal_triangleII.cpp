#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            if (rowIndex < 1)
                return vector<int>(1, 1);
            if (rowIndex < 2)
                return vector<int>(2,1);
            int *buf = new int[rowIndex+1];
            buf[rowIndex-2] = 1;
            buf[rowIndex-1] = 2;
            buf[rowIndex] = 1;
            int row = 2;
            while (row < rowIndex) {
                buf[rowIndex-row-1] = 1;
                for (int i = rowIndex-row; i < rowIndex; i++) {
                    buf[i] = buf[i] + buf[i+1];
                }
                row++;
            }
            vector<int> ret;
            for (int i = 0; i <= rowIndex; i++) {
                ret.push_back(buf[i]);
            }
            return ret;
        }
};

int main(void)
{
    vector<int> vec = Solution().getRow(8);
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}
