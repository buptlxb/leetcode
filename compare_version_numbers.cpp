#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        void strim(vector<string> &vec) {
            while (!vec.empty() && string2int(vec.back()) == 0) {
                vec.pop_back();
            }
        }

        void split(string str, vector<string> &vec) {
            string::iterator iter = str.begin();
            while (iter != str.end()) {
                
                string tmp;
                while (*iter != '.' && iter != str.end()) {
                    tmp.push_back(*iter);
                    iter++;
                }
                vec.push_back(tmp);
                if (*iter == '.')
                    iter++;
            }
        }

        int string2int(string str) {
            int ret = 0;
            for (string::iterator iter = str.begin(); iter != str.end(); iter++) {
                ret = ret * 10 + *iter - '0';
            }
            return ret;
        }

        int compareVersion(string version1, string version2) {
            vector<string> v1, v2;
            split(version1, v1);
            split(version2, v2);
            strim(v1);
            strim(v2);
            vector<string>::iterator iter1 = v1.begin(), iter2 = v2.begin(); 
            while (iter1 != v1.end() && iter2 != v2.end()) {

                int num1 = string2int(*iter1);
                int num2 = string2int(*iter2);

                if (num1 == num2) {
                    num1 = 0;
                    num2 = 0;
                } else if (num1 < num2) {
                    return -1;
                } else {
                    return 1;
                }
                iter1++;
                iter2++;
            }
            if (iter1 != v1.end())
                return 1;
            if (iter2 != v2.end())
                return -1;
            return 0;
        }
};

int main(void)
{
    string v1 = "0";
    string v2 = "1";
    vector<string> vec;
    Solution().split(v2, vec);
    Solution().strim(vec);
    for (vector<string>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter << "->" << Solution().string2int(*iter) << endl;
    }
    cout << v1 << " < " << v2 << ": " << Solution().compareVersion(v1, v2) << endl;
    return 0;
}
