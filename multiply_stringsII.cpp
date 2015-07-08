#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int atoi(char c) { return c - '0'; }
    char itoa(int x) { return x + '0'; }
    string multiply(string num1, string num2) {
        vector<int> vec(num1.size()+num2.size(), 0);
        string::size_type ii = 0, jj = 0;
        for (string::reverse_iterator i = num1.rbegin(), iend = num1.rend(); i != iend; ++i, ++ii) {
            jj = 0;
            for (string::reverse_iterator j = num2.rbegin(), jend = num2.rend(); j != jend; ++j, ++jj) {
                vec[ii+jj] += atoi(*i) * atoi(*j);
            }
        }
        int carry = 0;
        string result;
        for (vector<int>::iterator i = vec.begin(), iend = vec.end(); i != iend; ++i) {
            *i += carry;
            result.push_back(itoa(*i%10));
            carry = *i / 10;
        }
        string::size_type found = result.find_last_not_of('0');
        if (found != string::npos)
            result.erase(found+1);
        else
            return "0";
        return string(result.rbegin(), result.rend());
    }
};

int main(void)
{
    string num1, num2;
    while (cin >> num1 >> num2) {
        cout << Solution().multiply(num1, num2) << endl;
    }
    return 0;
}
