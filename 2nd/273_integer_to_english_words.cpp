#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>

using namespace std;

class Solution {
public:
    typedef vector<string>::size_type sz_t;
    string numberToWords(int num) {
        ostringstream os;
        int base = 1000000000;
        for (sz_t i = others.size(); num && i > 0; --i) {
            string tmp = numberToWords(num/base, false);
            if (tmp.size())
                os << tmp << " " << others[i-1];
            num %= base;
            if (tmp.size() && num)
                os << " ";
            base /= 1000;
        }
        os << numberToWords(num%1000, os.str().size() == 0);
        return os.str();
    }
    string numberToWords(int num, bool tail) {
        assert(num < 1000);
        if (num == 0)
            return tail ? ones[num] : "";
        int a = num / 100, b = num % 100, c = num % 10;
        ostringstream os;
        if (a)
            os << ones[a] << " Hundred";
        if (a && b)
            os << " ";
        if (b > 19) {
            os << tens[b/10];
            if (c)
                os << " " << ones[c];
        } else if (b > 0) {
            os << ones[b];
        }
        return os.str();
    }
    Solution() {
        ones.push_back("Zero");
        ones.push_back("One");
        ones.push_back("Two");
        ones.push_back("Three");
        ones.push_back("Four");
        ones.push_back("Five");
        ones.push_back("Six");
        ones.push_back("Seven");
        ones.push_back("Eight");
        ones.push_back("Nine");
        ones.push_back("Ten");
        ones.push_back("Eleven");
        ones.push_back("Twelve");
        ones.push_back("Thirteen");
        ones.push_back("Fourteen");
        ones.push_back("Fifteen");
        ones.push_back("Sixteen");
        ones.push_back("Seventeen");
        ones.push_back("Eighteen");
        ones.push_back("Nineteen");

        tens.push_back("");
        tens.push_back("");
        tens.push_back("Twenty");
        tens.push_back("Thirty");
        tens.push_back("Forty");
        tens.push_back("Fifty");
        tens.push_back("Sixty");
        tens.push_back("Seventy");
        tens.push_back("Eighty");
        tens.push_back("Ninety");

        others.push_back("Thousand");
        others.push_back("Million");
        others.push_back("Billion");
    }
private:
        vector<string> ones, tens, others;
};

int main(void)
{
    Solution s;
    assert(s.numberToWords(20) == "Twenty");
    assert(s.numberToWords(100) == "One Hundred");
    assert(s.numberToWords(1000) == "One Thousand");
    assert(s.numberToWords(123) == "One Hundred Twenty Three");
    assert(s.numberToWords(12345) == "Twelve Thousand Three Hundred Forty Five");
    assert(s.numberToWords(1234567) == "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven");
    return 0;
}
