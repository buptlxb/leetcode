#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::cout;
using std::endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root)
            return ret;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<TreeNode *> nodes;
            vector<int> tmp;
            while (!q.empty()) {
                nodes.push_back(q.front());
                tmp.push_back(q.front()->val);
                q.pop();
            }
            ret.push_back(tmp);
            for (vector<TreeNode *>::iterator iter = nodes.begin(); iter != nodes.end(); iter++) {
                if ((*iter)->left)
                    q.push((*iter)->left);
                if ((*iter)->right)
                    q.push((*iter)->right);
            }
        }
        return ret;
    }
};

int main(void)
{
    TreeNode a1(3);
    TreeNode a2(9);
    TreeNode a3(20);
    TreeNode a4(15);
    TreeNode a5(7);
    a1.left = &a2;
    a1.right = &a3;
    a3.left = &a4;
    a3.right = &a5;
    vector<vector<int> > ret = Solution().levelOrder(&a1);
    for (vector<vector<int> >::iterator iter = ret.begin(); iter != ret.end(); iter++) {
        for (vector<int>::iterator i = iter->begin(); i != iter->end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
}
