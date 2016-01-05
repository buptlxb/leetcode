#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       map<int, int> m;
       for (auto x : nums) {
           if (m[x])
               return true;
           ++m[x];
       }
       return false;
    }
};

int main(void)
{
    return 0;
}
