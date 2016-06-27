#include <iostream>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        while (b % a) {
            int tmp = a;
            a = b % a;
            b = tmp;
        }
        return a;
    }

    void rotate(int nums[], int n, int k) {
        k %= n;
        if (k == 0)
            return;
        k = n - k;
        int len = gcd(n, k);
        cout << len << endl;
        for (int i = 0; i < len; i++) {
            int tmp = nums[i];
            int j = i;
            while (1) {
                int d = j + k;
                if (d >= n)
                    d -= n;
                if (d == i)
                    break;
                nums[j] = nums[d];
                j = d;
            }
            nums[j] = tmp;
        }
    }
};

void print_array(int nums[], int len)
{
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

int main(void)
{
    int nums[] = {1,2,3,4,5};
    int len = sizeof(nums) / sizeof(nums[0]);
    print_array(nums, len);
    Solution().rotate(nums, len, 2);
    print_array(nums, len);
    return 0;
}
