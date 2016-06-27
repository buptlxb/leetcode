#include <iostream>

using namespace std;

class Solution {
    private :
        int max3(int a, int b, int c) {
            int tmp = a > b ? a : b;
            return tmp > c ? tmp : c;
        }
        int min3(int a, int b, int c) {
            int tmp = a < b ? a : b;
            return tmp < c ? tmp : c;
        }
    public :
        int maxProduct(int a[], int n) {
            int *max = new int[n];
            int *min = new int[n];
            max[0] = a[0];
            min[0] = a[0];
            int curr_max = a[0];
            for (int i = 1; i < n; i++) {
                max[i] = max3(a[i], a[i]*max[i-1], a[i]*min[i-1]);
                min[i] = min3(a[i], a[i]*max[i-1], a[i]*min[i-1]);
                if (max[i] > curr_max)
                    curr_max = max[i];
            }
            return curr_max;
        }
};

int main(void)
{
    int a[] = {2, 3, -2, 4};
    Solution s;
    cout << s.maxProduct(a, sizeof(a)/sizeof(a[0])) << endl;
    return 0;
}
