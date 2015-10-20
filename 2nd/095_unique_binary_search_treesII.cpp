#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    typedef vector<TreeNode *>::iterator TNIter;
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> ret;
        generateTrees(1, n, ret);
        return ret;
    }
    void generateTrees(int a, int b, vector<TreeNode *>&ret) {
        if (a > b) {
            ret.push_back(NULL);
            return;
        }
        for (int k = a; k <= b; ++k) {
            vector<TreeNode *> ltrees, rtrees;
            generateTrees(a, k-1, ltrees);
            generateTrees(k+1, b, rtrees);
            for (TNIter i = ltrees.begin(), iend = ltrees.end(); i != iend; ++i) {
                for (TNIter j = rtrees.begin(), jend = rtrees.end(); j != jend; ++j) {
                    ret.push_back(new TreeNode(k));
                    ret.back()->left = *i;
                    ret.back()->right = *j;
                }
            }
        }
    }
};


int main(void)
{
    return 0;
}
