#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (true) {
            int x = q.front();
            q.pop();
            if (q.empty())
                break;
            p.push(x);
        }
        p.swap(q);
    }

    // Get the top element.
    int top() {
        int x;
        while (!q.empty()) {
            x = q.front();
            q.pop();
            p.push(x);
        }
        p.swap(q);
        return x;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty() && p.empty();
    }
private:
    queue<int> p, q;
};

int main(void)
{
    return 0;
}
