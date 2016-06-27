#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        if (p && !q || !p && q || p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
    cout << Solution().isSameTree(&a11, &a11) << endl;
}
