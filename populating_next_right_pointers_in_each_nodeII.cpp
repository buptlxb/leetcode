#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;


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
            TreeLinkNode *head = NULL;
            TreeLinkNode *last = NULL;
            TreeLinkNode *cur = root;
            while (cur) {
                if (!head) {
                    if (cur->left)
                        head = cur->left;
                    else if (cur->right)
                        head = cur->right;
                }
                if (cur->left) {
                    if (last)
                        last->next = cur->left;
                    last = cur->left;
                }
                if (cur->right) {
                    if (last)
                        last->next = cur->right;
                    last = cur->right;
                }
                if (cur->next) {
                    cur = cur->next;
                } else {
                    cur = head;
                    head = NULL;
                    last = NULL;
                }
            }
        }
};

int main(void)
{

}
