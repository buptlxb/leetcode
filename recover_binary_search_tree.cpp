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
    TreeNode *prev, *s1, *s2;
public:
    void recoverTree(TreeNode *root) {
        if (!root)
            return;
        inorderCheck(root);
        int tmp = s1->val;
        s1->val = s2->val;
        s2->val = tmp;
    }
    void inorderCheck(TreeNode *root) {
        if (!root)
            return;
        inorderCheck(root->left);
        if (prev && prev->val > root->val) {
            if (s1 == NULL) {
                s1 = prev;
                s2 = root;
            } else
                s2 = root;
        }
        prev = root;
        inorderCheck(root->right);
    }
    void inorderTraversal(TreeNode *root) {
        if (!root)
            return;
        inorderTraversal(root->left);
        cout << root->val << endl;
        inorderTraversal(root->right);
    }
};

int main(void)
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    n4.left = &n2;
    n4.right = &n5;
    n2.left = &n1;
    n5.left = &n3;
    TreeNode *root = &n4;
    Solution().inorderTraversal(root);
    Solution().recoverTree(root);
    Solution().inorderTraversal(root);
    return 0;
}
