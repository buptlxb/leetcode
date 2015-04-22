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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root)
            return ret;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        bool flag = true;
        vector<int> tmp;
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
            tmp.push_back(cur->val);
            if (q.front() == NULL) {
                q.pop();
                if (!q.empty())
                    q.push(NULL);
                if (flag)
                    ret.push_back(tmp);
                else
                    ret.push_back(vector<int>(tmp.rbegin(), tmp.rend()));
                tmp.clear();
                flag = !flag;
            }
        }
        return ret;
    }
};

int main(void)
{
    TreeNode n1(3);
    TreeNode n2(9);
    TreeNode n3(20);
    TreeNode n4(15);
    TreeNode n5(7);
    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;
    vector<vector<int> > ret = Solution().zigzagLevelOrder(&n1);
    cout << "[" << endl;
    for (vector<vector<int> >::iterator i = ret.begin(), iend = ret.end(); i != iend; ++i) {
        cout << "[";
        for (vector<int>::iterator j = i->begin(), jend = i->end(); j != jend; ++j) {
            cout << *j << ", ";
        }
        cout << "], " << endl;
    }
    cout << "]" << endl;
    return 0;
}
