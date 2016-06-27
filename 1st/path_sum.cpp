#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;
        vector<TreeNode*> stack;
        vector<int> sums;
        stack.push_back(root);
        sums.push_back(root->val);
        while (!stack.empty()) {
            TreeNode *tmp = stack.back();
            if (tmp->left) {
                stack.push_back(tmp->left);
                sums.push_back(sums.back() + tmp->left->val);
            } else if (tmp->right) {
                stack.pop_back();
                int cur_sum = sums.back();
                sums.pop_back();
                stack.push_back(tmp->right);
                sums.push_back(cur_sum + tmp->right->val);
            } else {
                if (sums.back() == sum) {
                    return true;
                }
                stack.pop_back();
                sums.pop_back();
                while (!stack.empty() && stack.back()->right == NULL) {
                    stack.pop_back();
                    sums.pop_back();
                }
                if (!stack.empty()) {
                    TreeNode *tmp = stack.back();
                    stack.pop_back();
                    stack.push_back(tmp->right);
                    int cur_sum = sums.back();
                    sums.pop_back();
                    sums.push_back(cur_sum + tmp->right->val);
                }
            }
        }
        return false;
    }
};

int main(void)
{
    TreeNode root(5);
    TreeNode t1(4);
    TreeNode t2(8);
    TreeNode t3(11);
    TreeNode t4(13);
    TreeNode t5(4);
    TreeNode t6(7);
    TreeNode t7(2);
    TreeNode t8(1);
    root.left = &t1;
    root.right = &t2;
    t1.left = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;
    t5.right = &t8;
    int sum = 22;
    cout << Solution().hasPathSum(&root, sum) << endl;
    return 0;
}
