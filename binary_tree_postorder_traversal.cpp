#include <iostream>
#include <vector>
#include <stack>

using std::endl;
using std::cout;
using std::vector;
using std::stack;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vec;
        stack<TreeNode *> s;
        TreeNode *last_visited = NULL;
        while (!s.empty() || root) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                TreeNode *parent = s.top();
                if (parent->right && last_visited != parent->right) {
                    root = parent->right;
                } else {
                    vec.push_back(parent->val);
                    last_visited = parent;
                    s.pop();
                }
            }
        }
        return vec;
    }
    void postorderTraversal(TreeNode *root, vector<int> &vec) {
        if (!root)
            return;
        postorderTraversal(root->left, vec);
        postorderTraversal(root->right, vec);
        vec.push_back(root->val);
    }
};

int main(void)
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    n1.right = &n2;
    n2.left = &n3;
    vector<int> ret = Solution().postorderTraversal(&n1);
    for (vector<int>::const_iterator i = ret.begin(), iend = ret.end(); i != iend; ++i) {
        cout << *i << endl;
    }
    return 0;
}
