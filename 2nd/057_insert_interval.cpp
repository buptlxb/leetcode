#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class IntervalCmp: public less<Interval> {
public:
    bool operator() (const Interval &lhs, const Interval &rhs) {
        return lhs.start < rhs.start || lhs.start == rhs.start && lhs.end < rhs.end;
    }
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> tmp(intervals), ret;
        tmp.push_back(newInterval);
        sort(tmp.begin(), tmp.end(), IntervalCmp());
        Interval t;
        for (vector<Interval>::iterator i = tmp.begin(), iend = tmp.end(); i != iend; ++i) {
            if (i == tmp.begin()) {
                t.start = i->start;
                t.end = i->end;
            } else {
                if (t.end >= i->start)
                    t.end = max(i->end, t.end);
                else {
                    ret.push_back(t);
                    t.start = i->start;
                    t.end = i->end;
                }
            }
        }
        ret.push_back(t);
        return ret;
    }
};

int main(void)
{
    return 0;
}
