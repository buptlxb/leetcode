#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isValid(char *array, char c) {
            if (c == '.')
                return true;
            if (array[c])
                return false;
            array[c] = 1;
            return true;
        }

        bool isValidSudoku(vector<vector<char> > &board) {
            char row[10] = {0, };
            char column[9][10] = {0, };
            char cell[9][10] = {0, };
            for (int i = 0; i < 9; i++) {
                memset(row, 0, 10);
                for (int j = 0; j < 9; j++) {
                    char tmp = board[i][j];
                    if (!isValid(row, tmp) || !isValid(column[j], tmp) || !isValid(cell[i/3*3 + j/3], tmp))
                        return false;
                }
            }
            return true;
        }
};

int main(void)
{
    return 0;
}
