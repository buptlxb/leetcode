#include <iostream>

using std::cout;
using std::endl;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root)
            return;
        TreeNode *right = root->right;
        flatten(root->left);
        root->right = root->left;
        root->left = NULL;
        flatten(right);
        while (root->right)
            root = root->right;
        root->right = right;
    }
};

int main(void)
{
    TreeNode a1(1);
    TreeNode a2(2);
    TreeNode a3(3);
    TreeNode a4(4);
    TreeNode a5(5);
    TreeNode a6(6);
    //a1.left = &a2;
    a1.right = &a5;
    //a2.left = &a3;
    //a2.right = &a4;
    //a5.right = &a6;
    Solution().flatten(&a1);
    TreeNode *cur = &a1;
    while (cur) {
        cout << cur->val << endl;
        cur = cur->right;
    }
    return 0;
}
