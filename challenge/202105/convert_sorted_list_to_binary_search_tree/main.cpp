#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
    ~ListNode() {
        delete next;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

TreeNode *sortedListToBST(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    // Find mid node
    ListNode *prev = nullptr;
    ListNode *p = head;
    ListNode *q = head;

    while (q != nullptr && q->next != nullptr) {
        prev = p;
        p = p->next;
        q = q->next->next;
    }

    if (prev != nullptr) {
        prev->next = nullptr;
    }

    TreeNode *ret = new TreeNode(p->val);
    if (head == p) {
        return ret;
    }

    ret->left = sortedListToBST(head);
    ret->right = sortedListToBST(p->next);

    return ret;
}

int main() {
    {
        ListNode *r = new ListNode(-10);
        r->next = new ListNode(-3);
        r->next->next = new ListNode(0);
        r->next->next->next = new ListNode(5);
        r->next->next->next->next = new ListNode(9);

        auto ret = sortedListToBST(r);
        assert(ret->val == 0);
        assert(ret->left->val == -3);
        assert(ret->left->left->val == -10);
        assert(ret->left->right == nullptr);
        assert(ret->right->val == 9);
        assert(ret->right->left->val == 5);
        assert(ret->right->right == nullptr);
    }
    {
        auto ret = sortedListToBST(nullptr);
        assert(ret == nullptr);
    }
    {
        ListNode *r = new ListNode(0);
        auto ret = sortedListToBST(r);
        assert(ret->val == 0);
        assert(ret->left == nullptr);
        assert(ret->right == nullptr);
    }
    {
        ListNode *r = new ListNode(1);
        r->next = new ListNode(3);

        auto ret = sortedListToBST(r);
        assert(ret->val == 3);
        assert(ret->left->val == 1);
        assert(ret->left->right == nullptr);
    }
    return 0;
}
