#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::cout;
using std::endl;
using std::map;
using std::pair;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        map<int, int> m;

        for (vector<int>::size_type i = 0; i != numbers.size(); i++) {
            map<int, int>::iterator it = m.find(target-numbers[i]);
            if (it != m.end()) {
                vector<int>::size_type j = it->second;
                if (j < i) {
                    ret.push_back(j+1);
                    ret.push_back(i+1);
                    return ret;
                }
            }
            m.insert(pair<int, int>(numbers[i], i));
        }
    }
};

int main(void)
{
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(11);
    vec.push_back(15);
    int target = 9;
    vector<int> ret = Solution().twoSum(vec, target);
    cout << ret[0] << ret[1] << endl;
    return 0;
}
