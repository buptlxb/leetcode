#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode *root) {
        return dfs(root).first;
    }
    pair<int, int> dfs(TreeNode *root) {
        pair<int, int> p(0, 0);
        if (root) {
            pair<int, int> pl = dfs(root->left), pr = dfs(root->right);
            p.second = pl.first + pr.first;
            p.first = max(p.second, root->val + pl.second + pr.second);
        }
        return p;
    }
};

int main(void)
{
    TreeNode n1(3);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(3);
    TreeNode n5(1);
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    n3.right = &n5;
    cout << Solution().rob(&n1) << endl;
    return 0;
}
