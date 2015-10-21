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
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int> > ret;
        if (!root)
            return ret;
        vector<int> tmp;
        ret.push_back(tmp);
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur) {
                ret.back().push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            } else if (!q.empty()) {
                ret.push_back(tmp);
                q.push(NULL);
            }
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
