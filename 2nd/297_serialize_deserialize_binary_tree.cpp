#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string toString(TreeNode *p) {
    return p ? to_string(p->val) : "null";
}

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<string> vec;
        while (!q.empty()) {
            TreeNode *cur = q.front();
            vec.push_back(toString(cur));
            q.pop();
            if (cur) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        auto x = find(vec.rbegin(), vec.rend(), "null");
        return join(vec.begin(), find_if_not(vec.rbegin(), vec.rend(), bind2nd(equal_to<string>(), "null")).base(), ",");
    }
    string join(vector<string>::iterator first, vector<string>::iterator last, string delim) {
        if (first == last)
            return "[]";
        ostringstream os;
        os << "[" << *first;
        while (++first != last) {
            os << "," << *first;
        }
        os << "]";
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        assert(data.size() > 1 && *data.begin() == '[' && *data.rbegin() == ']');
        TreeNode *root = nullptr;
        if (data.size() == 2)
            return root;
        queue<TreeNode *> q;
        bool left = true;
        for (string::iterator i = data.begin()+1, j = i, iend = data.end(); i != iend; ++i) {
            if (*i == ',' || *i == ']') {
                string tmp(j, i);
                j = i+1;
                TreeNode *cur = nullptr;
                if (tmp != "null") {
                    cur = getNode(stoi(tmp));
                    if (!root)
                        root = cur;
                }
                if (!q.empty()) {
                    if (left) {
                        q.front()->left = cur;
                    } else {
                        q.front()->right = cur;
                        q.pop();
                    }
                    left = !left;
                }
                if (cur)
                    q.push(cur);
            }
        }
        return root;
    }
    TreeNode *getNode(int x) { return new TreeNode(x); }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(void)
{
    Codec cc;
    //TreeNode *root = cc.deserialize("[1,2,3,null,null,4,5]");
    TreeNode *root = cc.deserialize("[1,null,2]");
    cout << cc.serialize(root) << endl;
    return 0;
}
