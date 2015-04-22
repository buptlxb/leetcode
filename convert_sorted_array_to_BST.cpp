#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(const vector<int> &num, int left, int right) {
        if (left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(num, left, mid-1);
        root->right = sortedArrayToBST(num, mid+1, right);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size()-1);
    }
};

void preorderTraversal(TreeNode *root)
{
    if (!root)
        return;
    preorderTraversal(root->left);
    cout << root->val << endl;
    preorderTraversal(root->right);
}

int main(void)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> num(array, &array[sizeof(array)/sizeof(array[0])]);
    TreeNode *ret = Solution().sortedArrayToBST(num);
    preorderTraversal(ret);
    return 0;
}
