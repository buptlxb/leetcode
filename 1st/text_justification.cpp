#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int leftWidth = maxWidth;
        vector<string> packed_words, ret;
        for (vector<string>::iterator i = words.begin(), iend = words.end(); i != iend; ++i) {
            if (!packed_words.empty())
                --leftWidth;
            if (leftWidth >= 0 && leftWidth >= i->size()) {
                packed_words.push_back(*i);
                leftWidth -= i->size();
            } else {
                if (packed_words.size() == 1) {
                    ret.push_back(packed_words.front()+string(leftWidth+1, ' '));
                } else {
                    string tmp;
                    int num;
                    for (vector<string>::size_type i = 0, iend = packed_words.size(); i < iend; ++i) {
                        if (i != 0) {
                            num = (leftWidth+iend-i) / (iend-i);
                            tmp.append(string(num+1, ' '));
                            leftWidth -= num;
                        }
                        tmp.append(packed_words[i]);
                    }
                    if (!tmp.empty())
                        ret.push_back(tmp);
                }
                packed_words.clear();
                packed_words.push_back(*i);
                leftWidth = maxWidth - i->size();
            }
        }
        if (!packed_words.empty()) {
            string tmp;
            int num;
            for (vector<string>::size_type i = 0, iend = packed_words.size(); i < iend; ++i) {
                if (i != 0) {
                    tmp.push_back(' ');
                }
                tmp.append(packed_words[i]);
            }
            tmp.append(string(maxWidth-tmp.size(), ' '));
            ret.push_back(tmp);
        } else {
            istringstream is(ret.back());
            ret.pop_back();
            string tmp, lastLine;
            while (is >> tmp) {
                if (!lastLine.empty())
                    lastLine.push_back(' ');
                lastLine.append(tmp);
            }
            lastLine.append(string(maxWidth-lastLine.size(), ' '));
            ret.push_back(lastLine);
        }
        return ret;
    }
};

ostream & operator<< (ostream &os, vector<string> vec)
{
    copy(vec.begin(), vec.end(), ostream_iterator<string>(os, "\n"));
    return os;
}

int main(void)
{
    //string array[] = {"This", "is", "an", "example", "of", "text", "justification."};
    string array[] = {"a", "b", "c", "d", "e"};
    //string array[] = {""};
    vector<string> words(array, array+sizeof(array)/sizeof(string));
    cout << Solution().fullJustify(words, 4) << endl;
    return 0;
}
