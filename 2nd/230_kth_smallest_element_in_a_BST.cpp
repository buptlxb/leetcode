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
    int kthSmallest(TreeNode* root, int k) {
        ret = cnt = 0;
        inOrder(root, k);
        return ret;
    }
    void inOrder(TreeNode* root, int k) {
        if (!root)
            return;
        inOrder(root->left, k);
        if (++cnt == k)
            ret = root->val;
        inOrder(root->right, k);
    }
private:
    int cnt, ret;
};

int main(void)
{
    return 0;
}
