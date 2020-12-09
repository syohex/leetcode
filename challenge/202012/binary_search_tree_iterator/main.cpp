#include <cassert>
#include <stack>

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

class BSTIterator {
  public:
    BSTIterator(TreeNode *root) {
        current_ = root;
    }

    int next() {
        while (current_ != nullptr) {
            stack_.push(current_);
            current_ = current_->left;
        }

        TreeNode *tmp = stack_.top();
        stack_.pop();

        current_ = tmp->right;
        return tmp->val;
    }

    bool hasNext() {
        return !(current_ == nullptr && stack_.empty());
    }

    std::stack<TreeNode *> stack_;
    TreeNode *current_;
};

int main() {
    {
        TreeNode *r = new TreeNode(7);
        r->left = new TreeNode(3);
        r->right = new TreeNode(15);
        r->right->left = new TreeNode(9);
        r->right->right = new TreeNode(20);

        BSTIterator b(r);
        assert(b.next() == 3);
        assert(b.next() == 7);
        assert(b.hasNext());
        assert(b.next() == 9);
        assert(b.hasNext());
        assert(b.next() == 15);
        assert(b.hasNext());
        assert(b.next() == 20);
        assert(!b.hasNext());
    }
    return 0;
}
