#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::vector;
using std::map;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    typedef vector<int>::const_iterator citer;
    typedef vector<int>::const_reverse_iterator criter;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        map<int, citer> hash;
        for (citer i = inorder.begin(), iend = inorder.end(); i != iend; ++i) {
            hash[*i] = i;
        }
        return buildTree(inorder.begin(), inorder.end(), postorder.rbegin(), postorder.rend(), hash);
    }

    TreeNode *buildTree(citer inL, citer inR, criter postL, criter postR, const map<int, citer> &hash) {
        if (inL == inR || postL == postR)
            return NULL;
        TreeNode *n = new TreeNode(*postL);
        citer index = hash.find(n->val)->second;
        n->left = buildTree(inL, index, inR-index+postL, postR, hash);
        n->right = buildTree(index+1, inR, postL+1, inR-index+postL, hash);
        return n;
    }
};

void inorderTraversal(TreeNode *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->val << endl;
    inorderTraversal(root->right);
}

int main(void)
{
    int array1[] = {1, 2, 3, 4};
    int array2[] = {1, 4, 3, 2};
    vector<int> inorder(array1, array1+sizeof(array1)/sizeof(array1[0]));
    vector<int> postorder(array2, array2+sizeof(array2)/sizeof(array2[0]));
    TreeNode *ret = Solution().buildTree(inorder, postorder);
    inorderTraversal(ret);
    return 0;
}
