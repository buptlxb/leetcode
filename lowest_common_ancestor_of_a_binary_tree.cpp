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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode *> pq, qq;
        lowestCommonAncestor(root, p, pq);
        lowestCommonAncestor(root, q, qq);
        TreeNode *ret = NULL;
        while (!pq.empty() && !qq.empty()) {
            if (pq.top() == qq.top()) {
                ret = pq.top();
                pq.pop();
                qq.pop();
            } else {
                break;
            }
        }
        return ret;
    }
    bool lowestCommonAncestor(TreeNode *root, TreeNode *p, stack<TreeNode *> &anc) {
        if (!root)
            return false;
        if (root == p) {
            anc.push(root);
            return true;
        }
        if (lowestCommonAncestor(root->left, p, anc)) {
            anc.push(root);
            return true;
        }
        if (lowestCommonAncestor(root->right, p, anc)) {
            anc.push(root);
            return true;
        }
    }
};

int main(void)
{
    TreeNode t1(3);
    TreeNode t2(5);
    TreeNode t3(1);
    TreeNode t4(6);
    TreeNode t5(2);
    TreeNode t6(0);
    TreeNode t7(8);
    TreeNode t8(7);
    TreeNode t9(4);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t4.right = &t7;
    t5.left = &t8;
    t5.right = &t9;
    TreeNode *root = &t1;
    TreeNode *p = &t2;
    TreeNode *q = &t9;
    cout << Solution().lowestCommonAncestor(root, p, q)->val << endl;
    return 0;
}
