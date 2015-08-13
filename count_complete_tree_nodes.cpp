#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

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
            int ret = 0;
            if (!root)
                return 0;
            int rh = right_height(root);
            int lh = left_height(root);
            if (rh == lh) {
                return pow(2, rh) - 1;
            } else {
                return countNodes(root->left) + countNodes(root->right) + 1;
            }
        }
        int right_height(TreeNode *root) {
            int right = 0;
            TreeNode *cur = root;
            while (cur) {
                cur = cur->right;
                ++right;
            }
            return right;
        }
        int left_height(TreeNode *root) {
            int left = 0;
            TreeNode *cur = root;
            while (cur) {
                cur = cur->left;
                ++left;
            }
            return left;
        }
};

int main(void)
{
    TreeNode n1(0);
    TreeNode n2(0);
    TreeNode n3(0);
    TreeNode n4(0);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;

    cout << Solution().countNodes(&n1) << endl;
    return 0;
}
