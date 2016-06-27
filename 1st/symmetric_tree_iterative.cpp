#include <iostream>
#include <queue>
#include <vector>

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

    bool isSymmetric(TreeNode *root) {
        if (!root || !root->left && !root->right)
            return true;
        if (root->left && !root->right || !root->left && root->right)
            return false;
        if (root->left->val != root->right->val)
            return false;
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        q1.push(root->left->left);
        q2.push(root->right->right);
        q1.push(root->left->right);
        q2.push(root->right->left);
        while (!q1.empty() && !q2.empty()) {
            TreeNode *n1 = q1.front();
            TreeNode *n2 = q2.front();
            q1.pop();
            q2.pop();
            if (!n1 && !n2)
                continue;
            if (!n1 && n2 || n1 && !n2 || n1->val != n2->val)
                return false;
            if (n1 && n2) {
                q1.push(n1->left);
                q2.push(n2->right);
                q1.push(n1->right);
                q2.push(n2->left);
            }
        }
        return true;
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
