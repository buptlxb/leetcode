#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
    typedef vector<int>::size_type size_type;
public:
    void quick_sort(vector<int> &num, size_type left, size_type right) {
        if (left + 1 > right)
            return;
        int i = left;
        int j = right;
        int pivot = num[i];
        while (i < j) {
            while (i < j && num[j] >= pivot)
                j--;
            if (i < j)
                num[i++] = num[j];
            while (i < j && num[i] <= pivot)
                i++;
            if (i < j)
                num[j--] = num[i];
        }
        num[i] = pivot;
        if (i != left)
            quick_sort(num, left, i-1);
        if (i != right)
            quick_sort(num, i+1, right);
    }

    void quick_sort(vector<int> &num) {
        int len = num.size();
        if (len < 2)
            return;
        quick_sort(num, 0, len-1);
    }

    vector<vector<int> > threeSum(vector<int> &num) {
        quick_sort(num);
        vector<vector<int> > ret;
        for (size_type i = 0; i < num.size(); i++) {
            if (num[i] > 0)
                break;
            if (i > 0 && num[i] == num[i-1])
                continue;
            int j = i + 1;
            int k = num.size()-1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[k]);
                    ret.push_back(tmp);
                    do {
                        j++;
                    } while (j < k && num[j] == num[j-1]);

                    do {
                        k--;
                    } while (j < k && num[k] == num[k+1]);

                } else if (j < k && sum < 0)
                    j++;
                else if (j < k && sum > 0)
                    k--;
            }
        }
        return ret;
    }
};

int main(void)
{
    vector<int> vec;
    vec.push_back(-2);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    //vec.push_back(-4);
    vector<vector<int> > ret = Solution().threeSum(vec);
    for (vector<vector<int> >::iterator i = ret.begin(); i != ret.end(); i++) {
        for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }
    Solution().quick_sort(vec);
    for (vector<int>::size_type i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
