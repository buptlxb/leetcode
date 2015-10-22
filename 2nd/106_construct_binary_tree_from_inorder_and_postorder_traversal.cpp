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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, Iter> m;
        for (Iter i = inorder.begin(), iend = inorder.end(); i != iend; ++i)
            m[*i] = i;
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end(), m); 
    }   
    TreeNode *buildTree(Iter inL, Iter inR, Iter postL, Iter postR, map<int, Iter> &m) {
        if (inL >= inR || postL >= postR)
            return NULL;
        int val = *(postR-1);
        TreeNode *root = new TreeNode(val);
        Iter r = m[val];
        root->right = buildTree(r+1, inR, postL+(r-inL), postR-1, m); 
        root->left = buildTree(inL, r, postL, postL+(r-inL), m); 
    }                                                                                                                                        
};

int main(void)
{
    return 0;
}
