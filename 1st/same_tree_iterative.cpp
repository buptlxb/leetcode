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
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        q1.push(p->left);
        q1.push(p->right);
        q2.push(q->left);
        q2.push(q->right);
        while (!q1.empty() && !q2.empty()) {
            TreeNode *n1 = q1.front();
            TreeNode *n2 = q2.front();
            q1.pop();
            q2.pop();
            if (!n1 && !n2)
                continue;
            if (!n1 && n2 || n1 && !n2 || n1->val != n2->val)
                return false;
            q1.push(n1->left);
            q1.push(n1->right);
            q2.push(n2->left);
            q2.push(n2->right);
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
    cout << Solution().isSameTree(&a11, &a11) << endl;
}
