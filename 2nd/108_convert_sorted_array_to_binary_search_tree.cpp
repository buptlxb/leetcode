#include <iostream>
#include <vector>

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums.begin(), nums.end());
    }
    TreeNode *sortedArrayToBST(Iter left, Iter right) {
        if (left >= right)
            return NULL;
        Iter mid = left + (right-left)/2;
        TreeNode *root = new TreeNode(*mid);
        root->left = sortedArrayToBST(left, mid);
        root->right = sortedArrayToBST(mid+1, right);
        return root;
    }
};

int main(void)
{
    return 0;
}
