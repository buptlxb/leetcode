#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> tmp;
        vector<vector<int> > quenes;
        solveNQueens(n, tmp, quenes);
        vector<vector<string> > ret;
        for (vector<vector<int> >::iterator i = quenes.begin(), iend = quenes.end(); i != iend; ++i) {
            vector<string> s_row;
            for (vector<int>::iterator j = i->begin(), jend = i->end(); j != jend; ++j) {
                string row(n, '.');
                row[*j] = 'Q';
                s_row.push_back(row);
            }
            ret.push_back(s_row);
        }
        return ret;
    }
    void solveNQueens(int n, vector<int> &pos, vector<vector<int> > &ret) {
        if (n == pos.size()) {
            ret.push_back(pos);
        } else {
            for (int i = 0; i < n; ++i) {
                if (!isConflict(pos, i)) {
                    pos.push_back(i);
                    solveNQueens(n, pos, ret);
                    pos.pop_back();
                }
            }
        }
    }
    bool isConflict(vector<int> pos, int x) {
        for (vector<int>::size_type i = 0, iend = pos.size(); i < iend; ++i) {
            if (pos[i] == x || iend - i == x - pos[i] || iend - i == pos[i] - x)
                return true;
        }
        return false;
    }
};

ostream & operator<< (ostream &os, vector<vector<string> > matrix)
{
    cout << "[" << endl;
    for (vector<vector<string> >::iterator i = matrix.begin(), iend = matrix.end(); i != iend; ++i) {
        cout << "\t[" << endl;
        for (vector<string>::iterator j = i->begin(), jend = i->end(); j != jend; ++j) {
            cout << "\t\t" << *j << endl;
        }
        cout << "\t]" << endl;;
    }
    cout << "]";
    return os;
}

int main(void)
{
    vector<vector<string> > ret = Solution().solveNQueens(4);
    cout << ret << endl;
}
