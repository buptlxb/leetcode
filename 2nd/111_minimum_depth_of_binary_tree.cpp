#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode *> q;
        if (!root)
            return depth;
        q.push(root);
        q.push(NULL);
        ++depth;
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (!cur) {
                if (!q.empty()) {
                    q.push(NULL);
                }
                ++depth;
            } else {
                if (!cur->left && !cur->right)
                    break;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return depth;
    }
};

int main(void)
{
    return 0;
}
