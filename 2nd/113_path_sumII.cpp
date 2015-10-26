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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ret;
        vector<int> tmp;
        pathSum(root, sum, tmp, ret);
        return ret;
    }
    void pathSum(TreeNode *root, int sum, vector<int> &tmp, vector<vector<int> > &ret) {
        if (!root)
            return;
        tmp.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) {
            ret.push_back(tmp);
        }
        if (root->left)
            pathSum(root->left, sum-root->val, tmp, ret);
        if (root->right)
            pathSum(root->right, sum-root->val, tmp, ret);
        tmp.pop_back();
    }
};

int main(void)
{
    return 0;
}
