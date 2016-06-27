#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void preorderTraversal(TreeNode *root, vector<int> &ret) {
        if (!root)
            return;
        ret.push_back(root->val);
        preorderTraversal(root->left, ret);
        preorderTraversal(root->right, ret);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        preorderTraversal(root, ret);
        return ret;
    }
};

int main(void)
{
    TreeNode a1(1);
    TreeNode a2(2);
    TreeNode a3(3);
    TreeNode a4(4);
    TreeNode a5(5);
    a1.left = &a2;
    a1.right = &a3;
    a3.left = &a4;
    a3.right = &a5;
    TreeNode *root = &a1;
    vector<int> ret = Solution().preorderTraversal(root);
    for (vector<int>::iterator i = ret.begin(); i != ret.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
