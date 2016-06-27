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
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if (leftDepth == 0)
            return rightDepth + 1;
        if (rightDepth == 0)
            return leftDepth + 1;
        return leftDepth < rightDepth ? leftDepth+1 : rightDepth+1;
    }
};

int main(void)
{
    TreeNode root(5);
    TreeNode t1(4);
    root.left = &t1;
    cout << Solution().minDepth(&root) << endl;
    return 0;
}
