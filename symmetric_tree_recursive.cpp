#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::queue;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right)
            return true;
        if (!left && right || left && !right || left->val != right->val)
            return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);
    }
};

int main(void)
{
    TreeNode a11(1);
    TreeNode a21(2);
    TreeNode a22(2);
    TreeNode a31(3);
    TreeNode a32(3);
    TreeNode a42(4);
    TreeNode a41(4);
    a11.left = &a21;
    a11.right = &a22;
    a21.left = &a31;
    a21.right = &a41;
    a22.left = &a42;
    a22.right = &a32;
    cout << Solution().isSymmetric(&a11) << endl;
    return 0;
}
