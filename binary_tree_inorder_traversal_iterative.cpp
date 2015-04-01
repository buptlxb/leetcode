#include <iostream>
#include <vector>

using namespace std;


class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_vector(vector<int> vec)
{
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;
}

class Solution {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> ret;
            vector<TreeNode*> s;
            TreeNode *cur = root;
            while (!s.empty() || cur) {
                if (cur) {
                    s.push_back(cur);
                    cur = cur->left;
                } else {
                    ret.push_back(s.back()->val);
                    cur = s.back()->right;
                    s.pop_back();
                }
            }
            return ret;
        }
};

int main(void)
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    t1.right = &t2;
    t2.left = &t3;
    vector<int> ret = Solution().inorderTraversal(&t1);
    print_vector(ret);
    return 0;
}
