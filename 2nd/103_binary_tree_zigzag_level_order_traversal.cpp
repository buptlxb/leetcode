#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ValueOf: public unary_function<int, TreeNode*> {
    int operator() (TreeNode *t) { return t->val; }
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if (!root)
            return ret;
        deque<TreeNode *> level;
        level.push_back(root);
        int last_level_count = 1, cur_level_count = 0;
        ret.push_back(vector<int> (1, root->val));
        vector<int> tmp;
        bool flag = true;
        while (!level.empty()) {
            TreeNode *cur = level.front();
            level.pop_front();
            if (cur->left) {
                ++cur_level_count;
                level.push_back(cur->left);
            }
            if (cur->right) {
                ++cur_level_count;
                level.push_back(cur->right);
            }
            --last_level_count;
            if (!last_level_count && !level.empty()) {
                ret.push_back(tmp);
                if (flag) {
                    transform(level.rbegin(), level.rend(), back_inserter(ret.back()), ValueOf());
                } else {
                    transform(level.begin(), level.end(), back_inserter(ret.back()), ValueOf());
                }
                flag = !flag;
                last_level_count = cur_level_count;
                cur_level_count = 0;
            }
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
