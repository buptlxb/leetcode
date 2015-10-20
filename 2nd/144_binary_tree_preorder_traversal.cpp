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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        bool done = false;
        while (!done) {
            if (cur) {
                ret.push_back(cur->val);
                s.push(cur);
            } else if (s.empty()) {
                done = true;
            } else {
                cur = s.top();
                s.pop();
                cur = cur->right;
            }
        }
    }
};

int main(void)
{
    return 0;
}
