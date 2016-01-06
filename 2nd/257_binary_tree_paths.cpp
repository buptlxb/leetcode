#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> ret;
        binaryTreePaths(root, path, ret);
        return ret;
    }
    void binaryTreePaths(TreeNode *root, vector<int> &path, vector<string> &ret) {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            ret.push_back(join(path.begin(), path.end(), "->"));
        } else {
            binaryTreePaths(root->left, path, ret);
            binaryTreePaths(root->right, path, ret);
        }
        path.pop_back();
    }
    string join(vector<int>::iterator first, vector<int>::iterator last, string delim) {
        ostringstream os;
        if (first == last)
            return os.str();
        os << *first;
        while (++first != last) {
            os << delim << *first;
        }
        return os.str();
    }
};

int main(void)
{
    return 0;
}
