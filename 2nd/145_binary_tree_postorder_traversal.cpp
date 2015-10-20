#include <iostream>
#include <vector>
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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *prev = NULL;
        vector<int> ret;
        if (!root)
            return ret;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            if (!prev || prev->left == cur || prev->right == cur) {
                if (cur->left)
                    s.push(cur->left);
                else if (cur->right)
                    s.push(cur->right);
            } else if (cur->left == prev) {
                if (cur->right)
                    s.push(cur->right);
            } else {
                ret.push_back(cur->val);
                s.pop();
            }
            prev = cur;
        }
    }
};

int main(void)
{
    return 0;
}
