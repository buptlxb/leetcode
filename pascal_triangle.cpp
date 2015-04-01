#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int> > generate(int numRows) {
            vector<vector<int> > ret;
            if (numRows < 1)
                return ret;
            ret.push_back(vector<int>(1, 1));
            if (numRows < 2)
                return ret;
            ret.push_back(vector<int>(2, 1));
            if (numRows < 3)
                return ret;
            int i = 3;
            while (i <= numRows) {
                vector<int> prev = ret.back();
                vector<int> next(1, 1);
                for (vector<int>::iterator iter = prev.begin()+1; iter != prev.end(); iter++) {
                    next.push_back(*iter + *(iter-1));
                }
                next.push_back(1);
                ret.push_back(next);
                i++;
            }
            return ret;
        }
};

int main(void)
{
    vector<vector<int> > vec = Solution().generate(0);
    for (vector<vector<int> >::iterator iter = vec.begin(); iter != vec.end(); iter++) {
        for (vector<int>::iterator ii = iter->begin(); ii != iter->end(); ii++) {
            cout << *ii << " ";
        }
        cout << endl;
    }
    return 0;
}
