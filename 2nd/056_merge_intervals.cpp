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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if (intervals.empty())
            return ret;
        sort(intervals.begin(), intervals.end(), IntervalCmp());
        Interval t;
        for (vector<Interval>::iterator i = intervals.begin(), iend = intervals.end(); i != iend; ++i) {
            if (i == intervals.begin()) {
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
    Interval a1(1, 3);
    Interval a2(2, 6); 
    Interval a3(8, 10);
    Interval a4(15, 18);
    vector<Interval> intervals;
    intervals.push_back(a1);
    intervals.push_back(a2);
    intervals.push_back(a3);
    intervals.push_back(a4);
    vector<Interval> ret = Solution().merge(intervals);
    for (vector<Interval>::iterator i = ret.begin(), iend = ret.end(); i != iend; ++i) {
        cout << i->start << ", " << i->end << endl;
    }
    return 0;
}
