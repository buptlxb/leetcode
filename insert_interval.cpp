#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval lhs, Interval rhs) {
    return lhs.start < rhs.start || lhs.start == rhs.start && lhs.end < lhs.end;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), cmp);
        if (intervals.size() < 2)
            return intervals;
        vector<Interval> ret;
        Interval tmp(intervals.front());
        for (vector<Interval>::size_type i = 1, iend = intervals.size(); i != iend; ++i) {
            if (tmp.start == intervals[i].start || tmp.end >= intervals[i].start) {
                if (intervals[i].end > tmp.end)
                    tmp.end = intervals[i].end;
            } else {
                ret.push_back(tmp);
                tmp = intervals[i];
            }
        }
        ret.push_back(tmp);
        return ret;
    }
};

ostream & operator<< (ostream &os, const vector<Interval> &intervals) {
    for (vector<Interval>::const_iterator i = intervals.begin(), iend = intervals.end(); i != iend; ++i) {
        os << "[" << i->start << ", " << i->end << "]";
    }
    return os;
}

int main(void)
{
    Interval a1(1, 2);
    Interval a2(3, 5);
    Interval a3(6, 7);
    Interval a4(8, 10);
    Interval a5(12, 16);
    Interval newInterval(4, 9);
    vector<Interval> intervals;
    intervals.push_back(a1);
    intervals.push_back(a2);
    intervals.push_back(a3);
    intervals.push_back(a4);
    intervals.push_back(a5);
    vector<Interval> ret = Solution().insert(intervals, newInterval);
    cout << ret << endl;
    return 0;
}
