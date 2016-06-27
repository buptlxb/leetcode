#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::queue;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetricVector(const vector<int> &vec) {
        if (vec.empty())
            return true;
        vector<int>::size_type i = 0;
        vector<int>::size_type j = vec.size()-1;
        while (i < j) {
            if (vec[i++] != vec[j--])
                return false;
        }
        return true;
    }

    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            queue<TreeNode *>tmp;
            vector<int> values;
            while (!nodes.empty()) {
                TreeNode *node = nodes.front();
                if (node->left) {
                    tmp.push(node->left);
                    values.push_back(node->left->val);
                } else {
                    values.push_back(INT_MIN);
                }
                if (node->right) {
                    tmp.push(node->right);
                    values.push_back(node->right->val);
                } else {
                    values.push_back(INT_MIN);
                }
                nodes.pop();
            }
            if (!isSymmetricVector(values))
                return false;
            nodes = tmp;
        }
        return true;
    }
};

int main(void)
{
    TreeNode a11(1);
    TreeNode a21(2);
    TreeNode a22(2);
    TreeNode a31(3);
    TreeNode a32(3);
    TreeNode a42(4);
    TreeNode a41(4);
    a11.left = &a21;
    a11.right = &a22;
    a21.left = &a31;
    a21.right = &a41;
    a22.left = &a42;
    a22.right = &a32;
    cout << Solution().isSymmetric(&a11) << endl;
    return 0;
}
