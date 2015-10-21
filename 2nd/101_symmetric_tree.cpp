#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
    bool isSymmetric(TreeNode *r1, TreeNode *r2) {
        if (!r1)
            return !r2;
        if (!r2)
            return !r1;
        if (!isSymmetric(r1->left, r2->right))
            return false;
        if (r1->val != r2->val)
            return false;
        if (!isSymmetric(r1->right, r2->left))
            return false;
        return true;
    }
};

int main(void)
{
    return 0;
}
