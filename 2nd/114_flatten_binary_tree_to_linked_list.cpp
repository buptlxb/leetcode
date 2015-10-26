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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        if (root->left) {
            TreeNode *cur = root->left;
            while (cur->right) {
                cur = cur->right;
            }
            cur->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        flatten(root->right);
    }
};

int main(void)
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    TreeNode t6(6);
    t1.left = &t2;
    t1.right = &t5;
    t2.left = &t3;
    t2.right= &t4;
    t5.right = &t6;
    Solution().flatten(&t1);
    return 0;
}
