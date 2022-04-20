#include <cassert>
#include <functional>
#include <queue>

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
        std::function<void(TreeNode *)> f;
        f = [&](TreeNode *node) {
            if (node == nullptr) {
                return;
            }

            f(node->left);
            q_.push_back(node->val);
            f(node->right);
        };
        f(root);
    }

    int next() {
        int ret = q_.front();
        q_.pop_front();
        return ret;
    }

    bool hasNext() {
        return !q_.empty();
    }

    std::deque<int> q_;
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

        delete r;
    }
    return 0;
}
