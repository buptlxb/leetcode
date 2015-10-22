#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        if (height(root->left) + 1 < height(root->right) || height(root->left) > 1 + height(root->right))
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode *root) {
        if (!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};

int main(void)
{
    return 0;
}
