#include <cassert>
#include <vector>
#include <functional>

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

    bool equal(const TreeNode *other) const {
        if (other == nullptr) {
            return false;
        }

        if (val != other->val) {
            return false;
        }

        if (left != nullptr) {
            if (!left->equal(other->left)) {
                return false;
            }
        } else {
            if (other->left != nullptr) {
                return false;
            }
        }

        if (right != nullptr) {
            if (!right->equal(other->right)) {
                return false;
            }
        } else {
            if (other->right != nullptr) {
                return false;
            }
        }

        return true;
    }
};

std::vector<TreeNode *> generateTrees(int n) {
    std::function<std::vector<TreeNode *>(int start, int end)> f;
    f = [&f](int start, int end) -> std::vector<TreeNode *> {
        if (start > end) {
            return {nullptr};
        }
        std::vector<TreeNode *> ret;
        for (int i = start; i <= end; ++i) {
            auto lefts = f(start, i - 1);
            auto rights = f(i + 1, end);

            for (auto *left : lefts) {
                for (auto *right : rights) {
                    TreeNode *r = new TreeNode(i);
                    r->left = left;
                    r->right = right;

                    ret.push_back(r);
                }
            }
        }

        return ret;
    };

    return f(1, n);
}

int main() {
    {
        auto ret = generateTrees(3);
        assert(ret.size() == 5);

        TreeNode *r1 = new TreeNode(1);
        r1->right = new TreeNode(3);
        r1->right->left = new TreeNode(2);

        TreeNode *r2 = new TreeNode(1);
        r2->right = new TreeNode(2);
        r2->right->right = new TreeNode(3);

        TreeNode *r3 = new TreeNode(2);
        r3->left = new TreeNode(1);
        r3->right = new TreeNode(3);

        TreeNode *r4 = new TreeNode(3);
        r4->left = new TreeNode(2);
        r4->left->left = new TreeNode(1);

        TreeNode *r5 = new TreeNode(3);
        r5->left = new TreeNode(1);
        r5->left->right = new TreeNode(2);

        std::vector<TreeNode *> expected{r1, r2, r3, r4, r5};
        for (const auto &expect : expected) {
            bool ok = false;
            for (const auto &r : ret) {
                if (expect->equal(r)) {
                    ok = true;
                    break;
                }
            }

            if (!ok) {
                assert(false);
            }
        }

        for (size_t i = 0; i < expected.size(); ++i) {
            delete expected[i];
            delete ret[i];
        }
    }
    return 0;
}