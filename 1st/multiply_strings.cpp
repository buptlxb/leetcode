#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int atoi(char c) { return c - '0'; }
    char itoa(int x) { return x + '0'; }
    string multiply(string num1, string num2) {
        if (num1.size() > num2.size())
            return multiply(num2, num1);
        string result = "0", zeros;
        for (string::reverse_iterator i = num1.rbegin(), iend = num1.rend(); i != iend; ++i, zeros.push_back('0')) {
            char tmp = atoi(*i);
            if (!tmp)
                continue;
            string part = num2;
            while (tmp-- > 1) {
                part = add(part, num2);
            }
            part.append(zeros);
            result = add(result, part);
        }
        return result;
    }
    string add(string num1, string num2) {
        string result;
        if (num1.size() == 0)
            return num2;
        if (num2.size() == 0)
            return num1;
        string::reverse_iterator i = num1.rbegin(), j = num2.rbegin(), iend = num1.rend(), jend = num2.rend();
        char carry = 0;
        while (i != iend && j != jend) {
            char tmp = atoi(*i++) + atoi(*j++) + carry;
            carry = tmp / 10;
            tmp %= 10;
            result.push_back(itoa(tmp));
        }
        while (i != iend) {
            char tmp = atoi(*i++) + carry;
            carry = tmp / 10;
            tmp %= 10;
            result.push_back(itoa(tmp));
        }
        while (j != jend) {
            char tmp = atoi(*j++) + carry;
            carry = tmp / 10;
            tmp %= 10;
            result.push_back(itoa(tmp));
        }
        if (carry)
            result.push_back(itoa(carry));
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
