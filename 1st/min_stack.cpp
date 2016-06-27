#include <iostream>
#include <vector>

using namespace std;

class MinStack {
private:
        vector<int> vec;
        vector<int> min;
public:
    void push(int x) {
        vec.push_back(x);
        if (min.empty() || x <= min.back())
            min.push_back(x);
    }

    void pop() {
        int tmp = vec.back();
        vec.pop_back();
        if (tmp == min.back())
            min.pop_back();
    }

    int top() {
        return vec.back();
    }

    int getMin() {
        return min.back();
    }
};

int main(void)
{
    MinStack ms;
    ms.push(2);
    ms.push(0);
    ms.push(3);
    ms.push(0);
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    return 0;
}
