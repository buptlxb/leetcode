#include <iostream>
#include <deque>
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ret;
        if (!root)
            return ret;
        queue<TreeNode *> q;
        vector<int> tmp;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur) {
                tmp.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            } else {
                if (!q.empty())
                    q.push(NULL);
                ret.push_back(tmp);
                tmp.clear();
            }
        }
        return vector<vector<int> > (ret.rbegin(), ret.rend());
    }
};

int main(void)
{
    return 0;
}
