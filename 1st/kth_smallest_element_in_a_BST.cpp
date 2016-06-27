#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int cnt;
    int ret;
    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        inOrder(root, k);
        return ret;
    }
    void inOrder(TreeNode* root, int k) {
        if (!root)
            return;
        inOrder(root->left, k);
        ++cnt;
        if (cnt == k)
            ret = root->val;
        inOrder(root->right, k);
    }
};

int main(void)
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    n2.left = &n1;
    n2.right = &n3;
    cout << Solution().kthSmallest(&n2, 3) << endl;
    return 0;
}
