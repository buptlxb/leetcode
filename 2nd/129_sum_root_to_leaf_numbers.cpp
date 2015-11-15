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
    int sumNumbers(TreeNode* root) {
        int cur = 0, sum = 0;
        if (!root)
            return sum;
        sumNumbers(root, cur, sum);
        return sum;
    }
    void sumNumbers(TreeNode *root, int cur, int &sum) {
        cur = cur*10 + root->val;
        if (!root->left && !root->right)
            sum += cur;
        if (root->left) {
            sumNumbers(root->left, cur, sum);
        }
        if (root->right) {
            sumNumbers(root->right, cur, sum);
        }
    }
};

int main(void)
{
    return 0;
}
