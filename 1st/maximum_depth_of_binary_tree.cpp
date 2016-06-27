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
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
    }
};

int main(void)
{
    TreeNode root(5);
    TreeNode t1(4);
    TreeNode t2(8);
    TreeNode t3(11);
    TreeNode t4(13);
    TreeNode t5(4);
    TreeNode t6(7);
    TreeNode t7(2);
    TreeNode t8(1);
    root.left = &t1;
    root.right = &t2;
    t1.left = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;
    t5.right = &t8;
    //TreeNode root(5);
    //TreeNode t1(4);
    //root.left = &t1;
    cout << Solution().maxDepth(&root) << endl;
    return 0;
}
