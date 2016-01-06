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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> left, right;
        getPath(root, p, left);
        getPath(root, q, right);
        TreeNode *ret = NULL;
        for (auto i = left.rbegin(), j = right.rbegin(), iend = left.rend(), jend = right.rend(); i != iend && j != jend; ++i, ++j) {
            if (*i != *j)
                break;
            ret = *i;
        }
        return ret;
    }
    bool getPath(TreeNode *root, TreeNode *t, vector<TreeNode *> &path) {
        if (root == t) {
            path.push_back(t);
            return true;
        }
        if (!root)
            return false;
        if (root->left && getPath(root->left, t, path)) {
            path.push_back(root);
            return true;
        }
        if (root->right && getPath(root->right, t, path)) {
            path.push_back(root);
            return true;
        }
        return false;
    }
};

int main(void)
{
    return 0;
}
