#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    int minimumTotal(vector<vector<int> >& triangle) {
        if (triangle.empty())
            return 0;
        vector<int> min(triangle.back());
        for (s_t i = triangle.size()-1; i > 0; --i) {
            for (s_t j = 0, jend = triangle[i-1].size(); j < jend; ++j) {
                if (min[j] < min[j+1])
                    min[j] += triangle[i-1][j];
                else
                    min[j] = min[j+1] + triangle[i-1][j];
            }
        }
        return min[0];
    }
};

int main(void)
{
    vector<int> v1(1, 2);
    vector<int> v2;
    v2.push_back(3);
    v2.push_back(4);
    int a3[] = {6, 5, 7};
    vector<int> v3(a3, a3+sizeof(a3)/sizeof(int));
    int a4[] = {4, 1, 8, 3};
    vector<int> v4(a4, a4+sizeof(a4)/sizeof(int));
    vector<vector<int> > triangle;
    triangle.push_back(v1);
    triangle.push_back(v2);
    triangle.push_back(v3);
    triangle.push_back(v4);
    cout << Solution().minimumTotal(triangle) << endl;
    return 0;
}
