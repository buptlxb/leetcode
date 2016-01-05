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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        TreeNode *left = root, *right = root;
        int length = 0;
        while (left && right) {
            ++length;
            left = left->left;
            right = right->right;
        }
        if (!left)
            return (1 << length) - 1;
        return countNodes(root->left) + countNodes(root->right);
    }
};

int main(void)
{
    return 0;
}
