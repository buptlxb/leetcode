#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;

        queue<TreeNode *> q1;
        queue<int> q2;
        q1.push(root);
        q2.push(1);
        int ret = 0;
        while (!q1.empty()) {
            TreeNode *cur = q1.front();
            int depth = q2.front();
            q1.pop();
            q2.pop();
            if (cur->left) {
                q1.push(cur->left);
                q2.push(depth + 1);
                ret = ret > depth+1 ? ret : depth+1;
            }
            if (cur->right) {
                q1.push(cur->right);
                q2.push(depth + 1);
                ret = ret > depth+1 ? ret : depth+1;
            }
        }
        return ret;
    }
};

int main(void)
{
    TreeNode root(5);
    TreeNode t1(4);
    TreeNode t2(8);
    TreeNode t3(11);
    TreeNode t4(13);
    TreeNode t5(4);
    TreeNode t6(7);
    TreeNode t7(2);
    TreeNode t8(1);
    root.left = &t1;
    root.right = &t2;
    t1.left = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;
    t5.right = &t8;
    //TreeNode root(5);
    //TreeNode t1(4);
    //root.left = &t1;
    cout << Solution().maxDepth(&root) << endl;
    return 0;
}
