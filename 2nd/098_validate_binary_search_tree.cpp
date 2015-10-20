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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> s;
        TreeNode *prev = NULL, *cur = root;
        bool done = false;
        while (!done) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else if (s.empty()) {
                done = true;
            } else {
                cur = s.top();
                if (prev && prev->val >= cur->val)
                    return false;
                s.pop();
                prev = cur;
                cur = cur->right;
            }
        }
        return true;
    }
};

int main(void)
{
    return 0;
}
