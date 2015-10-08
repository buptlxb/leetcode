#include <iostream>

using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        TreeLinkNode *nextLevel = root->left;
        while (nextLevel) {
            while (root) {
                root->left->next = root->right;
                if (root->next)
                    root->right->next = root->next->left;
                root = root->next;
            }
            root = nextLevel;
            nextLevel = root->left;
        }
    }
    void connectRecursive(TreeLinkNode *root) {
        if (!root)
            return;
        if (root->left) {
            root->left->next = root->right;
            if (root->next)
                root->right->next = root->next->left;
        }
        connectRecursive(root->left);
        connectRecursive(root->right);
    }
};

int main(void)
{
    return 0;
}
