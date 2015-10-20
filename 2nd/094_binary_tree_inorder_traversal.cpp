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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorderTraversal(root, ret);
        return ret;
    }
    void inorderTraversal(TreeNode *root, vector<int> &ret) {
        if (!root)
            return;
        inorderTraversal(root->left, ret);
        ret.push_back(root->val);
        inorderTraversal(root->right, ret);
    }
    vector<int> inorderTraversalIter(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> ret;
        TreeNode *cur = root;
        bool done = false;
        while (!done) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else if (s.empty()) {
                done = true;
            } else {
                cur = s.top();
                ret.push_back(cur->val);
                s.pop();
                cur = cur->right;
            }
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
