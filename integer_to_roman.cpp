#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        ostringstream roman;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        for (int i = 0; num; ++i) {
            while (num >= value[i]) {
                roman << sym[i];
                num -= value[i];
            }
        }
        return roman.str();
    }
};

int main(void)
{
    cout << Solution().intToRoman(3999) << endl;
    return 0;
}
