class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0 || (num & (num-1)))
            return false;
        return isPowerofFourC(num) || isPowerofFourC(num >> 8) || isPowerofFourC(num >> 16) || isPowerofFourC(num >> 24);
    }
    bool isPowerofFourC(int num) {
        return (num & 0x1) || (num & 0x4) || (num &0x10) || (num & 0x40);
    }
    bool isPowerOfFourOneline(int num) {
        return (num > 0) && !(num & (num-1)) && !((num-1) % 3);
    }
};

int main(void)
{
    return 0;
}
