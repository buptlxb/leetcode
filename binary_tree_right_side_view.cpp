#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ret;
        if (!root)
            return ret;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        unsigned int count = 1;
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
            if (q.front() == NULL) {
                ret.push_back(cur->val);
                q.pop();
                if (!q.empty())
                    q.push(NULL);
            }
        }
        return ret;
    }
};

int main(void)
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    t1.left = &t2;
    t1.right = &t3;
    t2.right = &t5;
    t3.right = &t4;
    vector<int> ret = Solution().rightSideView(&t1);
    for (vector<int>::iterator i = ret.begin(); i != ret.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
