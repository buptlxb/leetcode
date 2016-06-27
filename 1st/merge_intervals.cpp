#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp1(const Interval &a, const Interval &b)
{
    return a.start < b.start || a.start == b.start && a.end < b.end;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if (intervals.size() < 2)
            return intervals;
        sort(intervals.begin(), intervals.end(), cmp1);
        Interval tmp(intervals.front());
        for (vector<Interval>::size_type i = 1, iend = intervals.size(); i != iend; ++i) {
            if (intervals[i].start == tmp.start || intervals[i].start <= tmp.end) {
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

ostream & operator<< (ostream &os, vector<Interval> vec)
{
    for (vector<Interval>::size_type i = 0, iend = vec.size(); i != iend; ++i) {
        cout << "[" << vec[i].start << ", " << vec[i].end <<  "]";
    }
    return os;
}

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
    cout << ret << endl;
    return 0;
}
