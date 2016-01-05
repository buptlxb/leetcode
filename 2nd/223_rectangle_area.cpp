#include <iostream>

using namespace std;

class Solution {
public:
    int area(int A, int B, int C, int D) {
        return (C - A) * (D - B);
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ret = area(A, B, C, D) + area(E, F, G, H);
        if (A >= G || C <= E || B >= H || D <= F)
            return ret;
        return ret - area(max(A, E), max(B, F), min(C, G), min(D, H));
    }
};

int main(void)
{
    cout << Solution().computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}
