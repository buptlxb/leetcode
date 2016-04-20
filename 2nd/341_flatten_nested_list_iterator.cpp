#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
    vector<NestedInteger> vec;
    int val;
    bool isInt;
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return isInt;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        assert(isInt);
        return val;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return vec;
    }
    NestedInteger() :isInt(false) {}
    NestedInteger(int x) : isInt(true), val(x) {}
    bool append(const NestedInteger &list) {
        if (isInt)
            return false;
        vec.push_back(list);
        return true;
    };
    bool append(int x) {
        return append(NestedInteger(x));
    }
};

class NestedIterator {
    typedef vector<NestedInteger>::const_iterator Iter;
    stack<pair<Iter, Iter>> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push(make_pair(nestedList.begin(), nestedList.end()));
        advance();
    }

    int next() {
        assert(!s.empty());
        int ret = (s.top().first++)->getInteger();
        advance();
        return ret;
    }

    bool hasNext() {
        return !s.empty();
    }

    void advance() {
        while (true) {
            while (s.top().first == s.top().second) {
                s.pop();
                if (s.empty())
                    break;
                ++s.top().first;
            }
            if (s.empty() || s.top().first->isInteger())
                break;
            const vector<NestedInteger> &list = s.top().first->getList();
            s.push(make_pair(list.begin(), list.end()));
        }
    }
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 */
int main(void)
{
    NestedInteger n1;
    n1.append(1);
    n1.append(1);
    vector<NestedInteger> nestedList{n1, 2, n1};
    NestedIterator i(nestedList);
    while (i.hasNext())
        cout << i.next() << endl;
    return 0;
}
