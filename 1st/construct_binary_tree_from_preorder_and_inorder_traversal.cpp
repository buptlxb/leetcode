#include <iostream>
#include <map>
#include <vector>


using std::cout;
using std::endl;
using std::map;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    typedef vector<int>::size_type size;
    typedef vector<int>::iterator iterator;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        map<int, iterator> hash;
        for (iterator i = inorder.begin(), iend = inorder.end(); i != iend; ++i)
        {
            hash[*i] = i;
        }
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end(), hash);
    }

    TreeNode *buildTree(iterator preL, iterator preR, iterator inL, iterator inR, map<int, iterator> hash) {
        if (preL >= preR || inL >= inR)
            return NULL;
        TreeNode *root = new TreeNode(*preL);
        iterator index = hash[root->val];
        root->left = buildTree(preL+1, index-inL+preL+1, inL, index, hash);
        root->right = buildTree(index-inL+preL+1, preR, index+1, inR, hash);
        return root;
    }

    void preorderTraversal(TreeNode *root)
    {
        if (!root)
            return;
        cout << root->val << endl;
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
};

int main(void)
{
    int array[] = {1, 2};
    vector<int> preorder(array, array+sizeof(array)/sizeof(array[0]));
    vector<int> inorder(preorder.rbegin(), preorder.rend());
    TreeNode *root = Solution().buildTree(preorder, inorder);
    Solution().preorderTraversal(root);
    return 0;
}
