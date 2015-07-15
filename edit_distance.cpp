#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> tmp(word2.size()+1, 0);
        vector<vector<int> > distance(word1.size()+1, tmp);
        for (string::size_type i = 0, isize = word1.size(); i <= isize; ++i) {
            distance[i][0] = i;
        }
        for (string::size_type j = 0, jsize = word2.size(); j <= jsize; ++j) {
            distance[0][j] = j;
        }
        for (string::size_type i = 1, isize = word1.size(); i <= isize; ++i) {
            for (string::size_type j = 1, jsize = word2.size(); j <= jsize; ++j) {
                distance[i][j] = min(distance[i-1][j], distance[i][j-1]) + 1;
                distance[i][j] = min(distance[i][j], distance[i-1][j-1]+ (word1[i-1] == word2[j-1] ? 0 : 1));
            }
        }
        return distance[word1.size()][word2.size()];
    }
};

int main(void)
{
    cout << Solution().minDistance("a", "ab") << endl;
    return 0;
}
