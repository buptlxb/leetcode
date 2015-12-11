#include <iostream>
#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root)
            return ret;
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
            if (q.front() == nullptr) {
                ret.push_back(cur->val);
                q.pop();
                if (!q.empty())
                    q.push(nullptr);
            }
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
