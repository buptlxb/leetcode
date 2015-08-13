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
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        int max = root->val;
        maxPathSum(root, max);
        return max;
    }
    int maxPathSum(TreeNode *root, int &max) {
        if (!root)
            return 0;
        int left_max = maxPathSum(root->left, max);
        int right_max = maxPathSum(root->right, max);
        int tmp = root->val;
        if (left_max > 0)
            tmp += left_max;
        if (right_max > 0)
            tmp += right_max;

        max = max > tmp ? max : tmp;
        int tmp_max = (left_max > right_max ? left_max : right_max) + root->val;
        return tmp_max > root->val ? tmp_max : root->val;
    }

};

int main(void)
{
    TreeNode t1(1);
    TreeNode t2(-2);
    TreeNode t3(3);
    TreeNode t4(3);
    t1.left = &t2;
    t1.right = &t3;
    //t3.left = &t4;
    cout << Solution().maxPathSum(&t1) << endl;
    return 0;
}
