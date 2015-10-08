#include <iostream>
#include <sstream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class List {
    public : 
        List() : root(NULL) {}
        List(ListNode *r) : root(r) {}
        void from_string(string);
        string to_string() const;
        ~List() {
            while (root) {
                ListNode *tmp = root;
                root = root->next;
                delete tmp;
            }
        }
        ListNode *getRoot() { return root; }
    private:
        ListNode *root;
};

void List::from_string(string str) {
    istringstream is(str);
    int val;
    ListNode *pos = root;
    while (is) {
        is >> val;
        if (is.fail()) {
            is.clear();
            is.get();
            continue;
        }
        if (pos) {
            pos->next = new ListNode(val);
            pos = pos->next;
        } else {
            root = new ListNode(val);
            pos = root;
        }
    }
}

string List::to_string() const {
    ostringstream os;
    ListNode *pos = root;
    while (pos->next) {
        os << pos->val << "->";
        pos = pos->next;
    }
    os << pos->val;
    return os.str();
}

ostream & operator<< (ostream &os, const List &list) {
    os << list.to_string();
    return os;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode ret(-1);
        ListNode *pos = &ret;
        while (l1 && l2) {
            int tmp = l1->val + l2->val + carry;
            carry = tmp / 10;
            pos->next = new ListNode(tmp % 10);
            pos = pos->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int tmp = l1->val + carry;
            carry = tmp / 10;
            pos->next = new ListNode(tmp % 10);
            pos = pos->next;
            l1 = l1->next;
        }
        while (l2) {
            int tmp = l2->val + carry;
            carry = tmp / 10;
            pos->next = new ListNode(tmp % 10);
            pos = pos->next;
            l2 = l2->next;
        }
        if (carry) {
            pos->next = new ListNode(carry);
            pos = pos->next;
        }
        return ret.next;
    }
};

int main(void)
{
    List list1, list2;
    list1.from_string("2 -> 4 -> 3");
    list2.from_string("5 -> 6 -> 4");
    cout << list1 << endl << list2 << endl;
    List ret(Solution().addTwoNumbers(list1.getRoot(), list2.getRoot()));
    cout << ret << endl;
    return 0;
}
