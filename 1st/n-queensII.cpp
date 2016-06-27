#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int totalNQueens(int n) {
        int ret = 0;
        vector<int> pos(n, -1);
        int row, column;
        row = 0;
        while (true) {
            for (column = pos[row]+1; column < n; ++column) {
                if (isConflict(pos, row, column))
                    continue;
                pos[row] = column;
                if (row == n-1) {
                    ++ret;
                } else {
                    ++row;
                    break;
                }
            }
            if (column == n) {
                if (row == 0)
                    break;
                pos[row] = -1;
                --row;
            }
        }
        return ret;
    }
    bool isConflict(const vector<int> &pos, int row, int column) {
        for (int i = 0; i < row; ++i) {
            if (column == pos[i] || column-pos[i] == row-i || column-pos[i] == i-row)
                return true;
        }
        return false;
    }
};

int main(void)
{
    cout << Solution().totalNQueens(4) << endl;
    return 0;
}
