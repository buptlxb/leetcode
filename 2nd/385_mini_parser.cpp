#include <iostream>
#include <vector>

using namespace std;


class NestedInteger {
    int val;
    vector<NestedInteger> list;
    bool isInt;
public:
    // Constructor initializes an empty nested list.
    NestedInteger() : isInt(false) {}

    // Constructor initializes a single integer.
    NestedInteger(int value) : val(value), isInt(true) {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const { return isInt; }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const { return val; }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
        list.clear();
        val = value;
        isInt = true;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
        isInt = false;
        list.push_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const { return list; }
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.size() == 0)
            return NestedInteger();
        if (s[0] == '[') {
            NestedInteger ret;
            for (int i = 1, iend = s.size()-1; i < iend; ) {
                int j = i;
                if (s[j] == '[') {
                    int match = 1;
                    ++j;
                    for (; match; ++j) {
                        if (s[j] == '[')
                            ++match;
                        else if (s[j] == ']')
                            --match;
                    }
                    ret.add(deserialize((s.substr(i, j-i))));
                    i = j + 1;
                } else {
                    int j = i;
                    for (; j < iend && s[j] != ','; ++j)
                        ;
                    ret.add(NestedInteger(stoi(s.substr(i, j-i+1))));
                    i = j + 1;
                }
            }
            return ret;
        }
        return NestedInteger(stoi(s));
    }
};

void print(NestedInteger &ni)
{
    if (ni.isInteger())
        cout << ni.getInteger();
    else {
        cout << '[';
        for (auto x : ni.getList()) {
            print(x);
            cout << ',';
        }
        cout << ']';
    }
}

int main(void)
{
    Solution s;
    //NestedInteger ni = s.deserialize("[123,[456,[789]]]");
    NestedInteger ni = s.deserialize("[[]]");
    print(ni);
    cout << endl;
    return 0;
}
