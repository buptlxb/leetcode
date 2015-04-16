#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_vector(vector<int> vec)
{
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;
}

class Solution {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> ret;
            TreeNode *cur = root;
            while (cur) {
                if (!cur->left) {
                    ret.push_back(cur->val);
                    cur = cur->right;
                } else {
                    TreeNode *rightmost = cur->left;
                    while (rightmost->right && rightmost->right != cur)
                        rightmost = rightmost->right;
                    if (rightmost->right != cur) {
                        ret.push_back(cur->val); // preorder
                        rightmost->right = cur;
                        cur = cur->left;
                    } else {
                        rightmost->right = NULL;
                        //ret.push_back(cur->val); // inorder
                        cur = cur->right;
                    }
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
    t1.right = &t2;
    t2.left = &t3;
    vector<int> ret = Solution().inorderTraversal(&t1);
    print_vector(ret);
    return 0;
}
