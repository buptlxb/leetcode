#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool inOrder(TreeNode *root, vector<int> &track) {
        if (!root)
            return true;
        if (!inOrder(root->left, track))
            return false;
        if (!track.empty() && track.back() >= root->val)
            return false;
        track.push_back(root->val);
        if (!inOrder(root->right, track))
            return false;
        return true;
    }

    bool isValidBST(TreeNode *root) {
        vector<int> track;
        return inOrder(root, track);
    }
};

int main(void)
{
    TreeNode a1(10);
    TreeNode a2(5);
    TreeNode a3(15);
    TreeNode a4(6);
    TreeNode a5(20);
    a1.left = &a2;
    a1.right = &a3;
    a3.left = &a4;
    a3.right = &a5;
    vector<int> track;
    Solution().inOrder(&a1, track);
    for (vector<int>::size_type i = 0; i < track.size(); i++)
        cout << track[i] << " ";
    cout << endl;
    cout << Solution().isValidBST(&a1) << endl;
    return 0;
}
