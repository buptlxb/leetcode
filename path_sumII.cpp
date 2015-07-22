#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ret;
        if (root) {
            vector<int> tmp;
            pathSum(root, sum, tmp, ret);
        }
        return ret;
    }
    void pathSum(TreeNode *root, int sum, vector<int> tmp, vector<vector<int> > &ret) {
        tmp.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) {
            ret.push_back(tmp);
        } else {
            if (root->left)
                pathSum(root->left, sum - root->val, tmp, ret);
            if (root->right)
                pathSum(root->right, sum - root->val, tmp, ret);
        }
    }
};

int main(void)
{
    TreeNode root(5);
    TreeNode t1(4);
    TreeNode t2(8);
    TreeNode t3(11);
    TreeNode t4(13);
    TreeNode t5(4);
    TreeNode t6(7);
    TreeNode t7(2);
    TreeNode t8(1);
    root.left = &t1;
    root.right = &t2;
    t1.left = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;
    t5.right = &t8;
    int sum = 22; 
    vector<vector<int> > ret = Solution().pathSum(&root, sum);
    cout << ret.size() << endl;
    for (vector<vector<int> >::size_type i = 0; i < ret.size(); ++i) {
        copy(ret[i].begin(), ret[i].end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
    return 0;
}
