#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (!root)
            return;
        while (root) {
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *top = s.top();
        s.pop();
        TreeNode *cur = top->right;
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        return top->val;
    }
private:
    stack<TreeNode *> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(void)
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    TreeNode t6(6);

    t3.left = &t2;
    t3.right = &t5;
    t2.left = &t1;
    t5.left = &t4;
    t5.right = &t6;
    TreeNode *root = &t3;

    BSTIterator i = BSTIterator(root);
    while (i.hasNext())
        cout << i.next() << " ";
    cout << endl;
    return 0;
}
