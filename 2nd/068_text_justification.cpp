#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int cur = 0;
        vector<string>::iterator start = words.begin();
        for (vector<string>::iterator i = words.begin(), iend = words.end(); i != iend; ++i) {
            cur += i->size();
            if (cur < maxWidth) {
                ++cur;
            } else if (cur == maxWidth) {
                ret.push_back(concatenate(start, i+1, cur, maxWidth));
                start = i+1;
                cur = 0;
            } else {
                ret.push_back(concatenate(start, i, cur-i->size()-1, maxWidth));
                start = i;
                cur = 0;
                --i;
            }
        }
        if (start == words.end())
            return ret;
        ret.push_back(concatenate(start, words.end(), cur-1, maxWidth, true));
        return ret;
    }
    string concatenate(vector<string>::iterator start, vector<string>::iterator end, int cur, int maxWidth, bool isleftAligned = false) {
        int total = maxWidth - cur;
        int slots = end - start - 1;
        ostringstream os;
        if (slots == 0) {
            os << *start << string(maxWidth-start->size(), ' ');
        } else {
            int spacesPerSlot = total / slots;
            int oneMore = total % slots;
            os << *start++;
            if (isleftAligned) {
                for (int i = 0; i < slots; ++i) {
                    os << ' ' << *start++;
                }
                os << string(maxWidth - cur, ' ');
            } else {
                string spaces(spacesPerSlot+1, ' ');
                for (int i = 0; i < slots; ++i) {
                    os << spaces;
                    if (i < oneMore)
                        os << ' ';
                    os << *start++;
                }
            }
        }
        return os.str();
    }
};

int main(void)
{
    return 0;
}
