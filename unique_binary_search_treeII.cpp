#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    typedef vector<TreeNode *>::size_type s_t;
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> ret;
        generateTrees(1, n+1, ret);
        return ret;
    }
    void generateTrees(int start, int end, vector<TreeNode *> &ret) {
        if (start >= end) {
            ret.push_back(NULL);
            return;
        }
        for (int i = start; i < end; ++i) {
            vector<TreeNode *> left;
            vector<TreeNode *> right;
            generateTrees(start, i, left);
            generateTrees(i+1, end, right);
            for (s_t j = 0; j < left.size(); ++j) {
                for (s_t k = 0; k < right.size(); ++k) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ret.push_back(root);
                }
            }
        }
    }
};

void printTree(ostream &os, TreeNode *root) {
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur) {
            cout << cur->val << ", ";
            q.push(cur->left);
            q.push(cur->right);
        } else if (!q.empty())
            cout << "#" << ", ";
    }
}

int main(void)
{
    vector<TreeNode *> ret = Solution().generateTrees(3);
    for (vector<TreeNode *>::iterator i = ret.begin(), iend = ret.end(); i != iend; ++i) {
        printTree(cout, *i);
        cout << endl;
    }
    return 0;
}
