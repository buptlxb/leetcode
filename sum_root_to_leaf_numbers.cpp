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
    int sumNumbers(TreeNode *root, int sum) {
        if (!root)
            return 0;
        int tmp = sum * 10 + root->val;
        if (!root->left && !root->right)
            return tmp;
        return sumNumbers(root->left, tmp) + sumNumbers(root->right, tmp);
    }

    int sumNumbers(TreeNode *root) {
        return sumNumbers(root, 0);
    }
};

int main(void)
{
    TreeNode a1(1);
    TreeNode a2(2);
    TreeNode a3(3);
    TreeNode a4(4);
    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    cout << Solution().sumNumbers(&a1) << endl;;
    return 0;
}
