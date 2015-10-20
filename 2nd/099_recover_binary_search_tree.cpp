#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode *> s;
        TreeNode *prev(NULL), *left(NULL), *right(NULL), *cur = root;
        bool done = false;
        while (!done) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else if (s.empty()) {
                done = true;
            } else {
                cur = s.top();
                if (prev && prev->val >= cur->val) {
                    if (!left) {
                        left = prev;
                        right = cur;
                    } else {
                        right = cur;
                        done = true;
                    }
                }
                s.pop();
                prev = cur;
                cur = cur->right;
            }
        }
        swap(left->val, right->val);
    }
    void recoverTreeConstSpace(TreeNode *root) {
        TreeNode *prev(NULL), *left(NULL), *right(NULL), *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *tmp = cur->left;
                while (tmp->right && tmp->right != cur)
                    tmp = tmp->right;
                if (tmp->right) {
                    tmp->right = NULL;
                    if (prev && prev->val >= cur->val) {
                        if (left) {
                            right = cur;
                        } else {
                            left = prev;
                            right = cur;
                        }
                    }
                    prev = cur;
                    cur = cur->right;
                } else {
                    tmp->right = cur;
                    cur = cur->left;
                }
            } else {
                if (prev && prev->val >= cur->val) {
                    if (left) {
                        right = cur;
                    } else {
                        left = prev;
                        right = cur;
                    }
                }
                prev = cur;
                cur = cur->right;
            }
        }
        swap(left->val, right->val);
    }
};

int main(void)
{
    return 0;
}
