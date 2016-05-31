#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct IntervalLess : less<Interval> {
    bool operator() (const Interval &lhs, const Interval &rhs) {
        return lhs.end < rhs.start;
    }
};

class SummaryRanges {
    set<Interval, IntervalLess> bst;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
        Interval t(val, val);
        if (bst.empty())
            bst.insert(t);
        auto p = bst.lower_bound(t);
        if (p == bst.end()) {
            --p;
            if (p->end+1 == val) {
                Interval n(p->start, val);
                bst.erase(p);
                bst.insert(n);
            } else
                bst.insert(t);
        } else if (p == bst.begin()) {
            if (p->start == val+1) {
                Interval n(val, p->end);
                bst.erase(p);
                bst.insert(n);
            } else
                bst.insert(t);
        } else {
            auto q = p--;
            if (p->end+1 == val && q->start == val+1) {
                Interval n(p->start, q->end);
                bst.erase(p);
                bst.erase(q);
                bst.insert(n);
            } else if (q->start == val+1) {
                Interval n(val, q->end);
                bst.erase(q);
                bst.insert(n);
            } else if (p->end+1 == val) {
                Interval n(p->start, val);
                bst.erase(p);
                bst.insert(n);
            } else
                bst.insert(t);
        }
    }
    
    vector<Interval> getIntervals() {
        return {bst.begin(), bst.end()};
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
int main(void)
{
    vector<int> data{1, 3, 7, 2, 6};
    SummaryRanges sr;
    for (auto x : data) {
        sr.addNum(x);
        for (auto &i : sr.getIntervals()) {
            cout << "(" << i.start << ", " << i.end << ") ";
        }
        cout << endl;
    }
    return 0;
}
