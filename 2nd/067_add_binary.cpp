#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    typedef string::reverse_iterator RIter;
    typedef string::iterator Iter;
    char atoi(char c) { return c - '0'; }
    char itoa(char c) { return c + '0'; }
    string addBinary(string a, string b) {
        string ret(a.size()+b.size()+1, '0');
        RIter i = a.rbegin(), iend = a.rend();
        RIter j = b.rbegin(), jend = b.rend();
        RIter index = ret.rbegin();
        char carry = 0;
        while (i != iend && j != jend) {
            *index = atoi(*i) + atoi(*j) + carry;
            carry = *index / 2;
            *index = itoa(*index % 2);
            ++index; ++i; ++j;
        }
        while (i != iend) {
            *index = atoi(*i) + carry;
            carry = *index / 2;
            *index = itoa(*index % 2);
            ++index; ++i;
        }
        while (j != jend) {
            *index = atoi(*j) + carry;
            carry = *index / 2;
            *index = itoa(*index % 2);
            ++index; ++j;
        }
        if (carry)
            *index = itoa(carry);
        Iter start = ret.begin(), end = ret.end();
        while (start != end) {
            if (*start != '0')
                break;
            ++start;
        }
        return start==end ? "0" : string(start, end);
    }
};

int main(void)
{
    return 0;
}
