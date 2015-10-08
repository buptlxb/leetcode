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
        if (root->left && root->right) {
            root->left->next = root->right;
        } else if (root->left) {
            TreeLinkNode *cur = root;
            while (cur->next) {
                if (cur->next->left) {
                    root->left->next = cur->next->left;
                    break;
                } else if (cur->next->right) {
                    root->left->next = cur->next->right;
                    break;
                }
                cur = cur->next;
            }
        }
        if (root->right) {
            TreeLinkNode *cur = root;
            while (cur->next) {
                if (cur->next->left) {
                    root->right->next = cur->next->left;
                    break;
                } else if (cur->next->right) {
                    root->right->next = cur->next->right;
                    break;
                }
                cur = cur->next;
            }
        }
        connect(root->right);
        connect(root->left);
    }
};

int main(void)
{
    TreeLinkNode t0(0);
    TreeLinkNode t1(1);
    TreeLinkNode t2(2);
    TreeLinkNode t3(3);
    TreeLinkNode t4(4);
    TreeLinkNode t5(5);
    TreeLinkNode t6(6);
    TreeLinkNode t7(7);
    TreeLinkNode t8(8);
    TreeLinkNode t9(9);
    TreeLinkNode t22(2);
    TreeLinkNode t00(0);
    TreeLinkNode t11(1);
    TreeLinkNode t77(7);
    TreeLinkNode t88(8);
    TreeLinkNode t111(1);
    t2.left = &t1;
    t2.right = &t3;
    t1.left = &t0;
    t1.right = &t7;
    t3.left = &t9;
    t3.right = &t111;
    t0.left = &t22;
    t7.left = &t11;
    t7.right = &t00;
    t00.left = &t77;
    t111.left = &t88;
    t111.right = &t8;
    Solution().connect(&t2);
    return 0;
}
