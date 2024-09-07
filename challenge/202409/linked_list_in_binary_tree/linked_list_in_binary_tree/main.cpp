#include <cassert>
#include <functional>
#include <cstdio>

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

bool isSubPath(ListNode *head, TreeNode *root) {
    std::function<bool(ListNode * list, TreeNode * node)> f;
    f = [&](ListNode *list, TreeNode *node) -> bool {
        if (list == nullptr) {
            return true;
        }
        if (node == nullptr) {
            return false;
        }

        if (node->val == list->val) {
            if (f(list->next, node->left) || f(list->next, node->right)) {
                return true;
            }
        }

        if (node->val == head->val) {
            if (f(head->next, node->left) || f(head->next, node->right)) {
                return true;
            }
        }

        return f(head, node->left) || f(head, node->right);
    };

    return f(head, root);
}

int main() {
    {
        ListNode *list = new ListNode(4);
        list->next = new ListNode(2);
        list->next->next = new ListNode(8);

        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(4);
        tree->left->right = new TreeNode(2);
        tree->left->right->left = new TreeNode(1);
        tree->right = new TreeNode(4);
        tree->right->left = new TreeNode(2);
        tree->right->left->left = new TreeNode(6);
        tree->right->left->right = new TreeNode(8);
        tree->right->left->right->left = new TreeNode(1);
        tree->right->left->right->right = new TreeNode(3);

        assert(isSubPath(list, tree));

        delete list;
        delete tree;
    }
    {
        ListNode *list = new ListNode(1);
        list->next = new ListNode(4);
        list->next->next = new ListNode(2);
        list->next->next->next = new ListNode(6);

        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(4);
        tree->left->right = new TreeNode(2);
        tree->left->right->left = new TreeNode(1);
        tree->right = new TreeNode(4);
        tree->right->left = new TreeNode(2);
        tree->right->left->left = new TreeNode(6);
        tree->right->left->right = new TreeNode(8);
        tree->right->left->right->left = new TreeNode(1);
        tree->right->left->right->right = new TreeNode(3);

        assert(isSubPath(list, tree));

        delete list;
        delete tree;
    }
    {
        ListNode *list = new ListNode(1);
        list->next = new ListNode(4);
        list->next->next = new ListNode(2);
        list->next->next->next = new ListNode(6);
        list->next->next->next->next = new ListNode(8);

        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(4);
        tree->left->right = new TreeNode(2);
        tree->left->right->left = new TreeNode(1);
        tree->right = new TreeNode(4);
        tree->right->left = new TreeNode(2);
        tree->right->left->left = new TreeNode(6);
        tree->right->left->right = new TreeNode(8);
        tree->right->left->right->left = new TreeNode(1);
        tree->right->left->right->right = new TreeNode(3);

        assert(!isSubPath(list, tree));

        delete list;
        delete tree;
    }
    {
        ListNode *list = new ListNode(1);
        list->next = new ListNode(10);

        TreeNode *tree = new TreeNode(1);
        tree->right = new TreeNode(1);
        tree->right->left = new TreeNode(10);
        tree->right->right = new TreeNode(1);
        tree->right->left->left = new TreeNode(9);

        assert(isSubPath(list, tree));

        delete list;
        delete tree;
    }
    {
        ListNode *list = new ListNode(2);
        list->next = new ListNode(2);
        list->next->next = new ListNode(1);

        TreeNode *tree = new TreeNode(2);
        tree->right = new TreeNode(2);
        tree->right->right = new TreeNode(2);
        tree->right->right->right = new TreeNode(1);

        assert(isSubPath(list, tree));

        delete list;
        delete tree;
    }
    return 0;
}
