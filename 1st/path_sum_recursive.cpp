#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;
        if (!root->left && !root->right && root->val == sum)
            return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
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
    int sum = 22;
    cout << Solution().hasPathSum(&root, sum) << endl;
    return 0;
}
