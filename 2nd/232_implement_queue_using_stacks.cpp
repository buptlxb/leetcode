#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        qCheck();
        alt.pop();
    }

    // Get the front element.
    int peek(void) {
        qCheck();
        return alt.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty() && alt.empty();
    }
private:
    void qCheck() {
        if (alt.empty()) {
            while (!s.empty()) {
                alt.push(s.top());
                s.pop();
            }
        }
    }
    stack<int> s, alt;
};

int main(void)
{
    return 0;
}
