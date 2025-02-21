#include <cassert>
#include <set>

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

class FindElements {
  public:
    FindElements(TreeNode *root) {
        root->val = 0;
        vals_.insert(root->val);
        init(root, vals_);
    }

    bool find(int target) {
        return vals_.find(target) != vals_.end();
    }

    void init(TreeNode *node, std::set<int> &vals) {
        if (node->left != nullptr) {
            node->left->val = node->val * 2 + 1;
            vals.insert(node->left->val);
            init(node->left, vals);
        }
        if (node->right != nullptr) {
            node->right->val = node->val * 2 + 2;
            vals.insert(node->right->val);
            init(node->right, vals);
        }
    }

    std::set<int> vals_;
};

int main() {
    {
        TreeNode *r = new TreeNode(-1);
        r->right = new TreeNode(-1);
        FindElements f(r);
        assert(!f.find(1));
        assert(f.find(2));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(-1);
        r->left = new TreeNode(-1);
        r->left->left = new TreeNode(-1);
        r->left->right = new TreeNode(-1);
        r->right = new TreeNode(-1);

        FindElements f(r);
        assert(f.find(1));
        assert(f.find(3));
        assert(!f.find(5));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(-1);
        r->right = new TreeNode(-1);
        r->right->left = new TreeNode(-1);
        r->right->left->left = new TreeNode(-1);
        FindElements f(r);
        assert(f.find(2));
        assert(!f.find(3));
        assert(!f.find(4));
        assert(f.find(5));
        delete r;
    }
    return 0;
}