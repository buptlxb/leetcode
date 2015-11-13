#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        maxPathSum(root, ret);
        return ret;
    }   
    int maxPathSum(TreeNode *root, int &ret) {
        if (!root)
            return 0;
        int left = max(maxPathSum(root->left, ret), 0);
        int right = max(maxPathSum(root->right, ret), 0);
        ret = max(left+right+root->val, ret);
        return max(left, right) + root->val;
    }   
};

int main(void)
{
    return 0;
}
