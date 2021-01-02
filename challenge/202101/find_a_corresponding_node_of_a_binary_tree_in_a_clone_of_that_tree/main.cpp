#include <cassert>
#include <functional>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

TreeNode *getTragetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
    std::function<std::vector<bool>(TreeNode * node, TreeNode * t, std::vector<bool> acc)> f;
    f = [&f](TreeNode *node, TreeNode *t, std::vector<bool> acc) -> std::vector<bool> {
        if (node == nullptr) {
            return std::vector<bool>{};
        }

        if (node == t) {
            return acc;
        }

        auto tmp = acc;
        tmp.push_back(true);
        auto ret = f(node->left, t, tmp);
        if (!ret.empty()) {
            return ret;
        }

        acc.push_back(false);
        return f(node->right, t, acc);
    };

    auto ways = f(original, target, std::vector<bool>{});
    TreeNode *p = cloned;
    for (bool is_left : ways) {
        if (is_left) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    return p;
}

int main() {
    {
        TreeNode *r = new TreeNode(7);
        r->left = new TreeNode(4);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(19);

        TreeNode *rr = new TreeNode(7);
        rr->left = new TreeNode(4);
        rr->right = new TreeNode(3);
        rr->right->left = new TreeNode(6);
        rr->right->right = new TreeNode(19);

        auto ret = getTragetCopy(r, rr, r->right);
        assert(ret == rr->right);

        delete r;
        delete rr;
    }
    {
        TreeNode *r = new TreeNode(7);
        TreeNode *rr = new TreeNode(7);
        auto ret = getTragetCopy(r, rr, r);
        assert(ret == rr);

        delete r;
        delete rr;
    }
    {
        TreeNode *r = new TreeNode(8);
        r->right = new TreeNode(6);
        r->right->right = new TreeNode(5);
        r->right->right->right = new TreeNode(4);
        r->right->right->right->right = new TreeNode(3);
        r->right->right->right->right->right = new TreeNode(3);
        r->right->right->right->right->right->right = new TreeNode(2);
        r->right->right->right->right->right->right->right = new TreeNode(1);

        TreeNode *rr = new TreeNode(8);
        rr->right = new TreeNode(6);
        rr->right->right = new TreeNode(5);
        rr->right->right->right = new TreeNode(4);
        rr->right->right->right->right = new TreeNode(3);
        rr->right->right->right->right->right = new TreeNode(3);
        rr->right->right->right->right->right->right = new TreeNode(2);
        rr->right->right->right->right->right->right->right = new TreeNode(1);

        auto ret = getTragetCopy(r, rr, r->right->right->right);
        assert(ret == rr->right->right->right);

        delete r;
        delete rr;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->left->left->left = new TreeNode(8);
        r->left->left->right = new TreeNode(9);
        r->left->right->left = new TreeNode(10);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(7);

        TreeNode *rr = new TreeNode(1);
        rr->left = new TreeNode(2);
        rr->left->left = new TreeNode(4);
        rr->left->right = new TreeNode(5);
        rr->left->left->left = new TreeNode(8);
        rr->left->left->right = new TreeNode(9);
        rr->left->right->left = new TreeNode(10);
        rr->right = new TreeNode(3);
        rr->right->left = new TreeNode(6);
        rr->right->right = new TreeNode(7);

        auto ret = getTragetCopy(r, rr, r->left->right);
        assert(ret == rr->left->right);

        delete r;
        delete rr;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(3);

        TreeNode *rr = new TreeNode(1);
        rr->left = new TreeNode(2);
        rr->left->left = new TreeNode(3);

        auto ret = getTragetCopy(r, rr, r->left);
        assert(ret == rr->left);

        delete r;
        delete rr;
    }
    return 0;
}
