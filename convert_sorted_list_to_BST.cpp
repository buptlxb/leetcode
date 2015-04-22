#include <iostream>

using std::cout;
using std::endl;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(int array[], int left, int right) {
        if (left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(array[mid]);
        root->left = sortedListToBST(array, left, mid-1);
        root->right = sortedListToBST(array, mid+1, right);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        if (!head)
            return NULL;
        int len = 0;
        ListNode *ptr = head;
        while (ptr) {
            ++len;
            ptr = ptr->next;
        }
        int *array = new int[len];
        ptr = head;
        for (int i = 0; i < len; ++i) {
            array[i] = ptr->val;
            ptr = ptr->next;
        }
        return sortedListToBST(array, 0, len-1);
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
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    ListNode n7(7);
    ListNode n8(8);
    ListNode n9(9);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    n8.next = &n9;
    TreeNode *ret = Solution().sortedListToBST(&n1);
    preorderTraversal(ret);
    return 0;
}
