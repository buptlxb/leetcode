#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
    return version >= 1702766719;
}

class Solution {
public:
    int firstBadVersion(int n) {
        return firstBadVersion(1, n);
    }
    int firstBadVersion(int first, int last) {
        if (first == last)
            return isBadVersion(first) ? first : numeric_limits<int>::max();
        else if (first > last)
            return numeric_limits<int>::max();
        int mid = first + (last - first)/2;
        if (isBadVersion(mid))
            return min(mid, firstBadVersion(first, mid-1));
        else
            return firstBadVersion(mid+1, last);
    }
};

int main(void)
{
    cout << Solution().firstBadVersion(2126753390) << endl;
    return 0;
}
