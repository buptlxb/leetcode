#include <iostream>
#include <vector>
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
    typedef vector<int>::iterator Iter;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, Iter> m;
        for (Iter i = inorder.begin(), iend = inorder.end(); i != iend; ++i) {
            m[*i] = i;
        }
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end(), m);
    }
    TreeNode* buildTree(Iter preL, Iter preR, Iter inL, Iter inR, map<int, Iter> &m) {
        if (preL >= preR || inL >= inR)
            return NULL;
        TreeNode *root = new TreeNode(*preL);
        Iter r = m[root->val];
        root->left = buildTree(preL+1, r-inL+preL+1, inL, r, m);
        root->right = buildTree(r-inL+preL+1, preR, r, inR, m);
        return root;
    }
};

int main(void)
{
    return 0;
}
