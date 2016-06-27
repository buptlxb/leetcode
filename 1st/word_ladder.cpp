#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::string;
using std::unordered_set;
using std::string;
using std::queue;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        string::size_type len = start.size();
        if (!len)
            return 0;
        queue<string> q;
        q.push(start);
        q.push("");
        int ret = 1;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (cur.size()) {
                for (string::size_type i = 0; i < len; i++) {
                    char tmp = cur[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == tmp)
                            continue;
                        cur[i] = c;
                        if (cur == end)
                            return ret + 1;
                        if (dict.find(cur) != dict.end()) {
                            q.push(cur);
                            dict.erase(cur);
                        }
                    }
                    cur[i] = tmp;
                }
            } else if (!q.empty()) {
                q.push("");
                ret++;
            }
        }
    }
};

int main(void)
{
    string start = "hit";
    string end = "cog";
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("doj");
    dict.insert("lot");
    dict.insert("log");
    cout << Solution().ladderLength(start, end, dict) << endl;
    return 0;
}
