#include <iostream>
#include <queue>
#include <cassert>
#include <functional>
#include <deque>

using namespace std;

class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, deque<int>, greater<int>> right;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        left.push(num);
        int adj = left.top();
        left.pop();
        right.push(adj);
        adj = right.top();
        if (left.size() + 1 < right.size()) {
            right.pop();
            left.push(adj);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        assert(right.size() > 0);
        if (left.size() == right.size())
            return (left.top() + right.top()) / 2.0;
        else
            return right.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main(void)
{
    MedianFinder mf;
    mf.addNum(1);
    cout << mf.findMedian() << endl;
    mf.addNum(2);
    cout << mf.findMedian() << endl;
    mf.addNum(3);
    cout << mf.findMedian() << endl;
    return 0;
}
