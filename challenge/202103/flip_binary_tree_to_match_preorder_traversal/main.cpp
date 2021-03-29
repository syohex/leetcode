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
};

std::vector<int> flipMatchVoyage(TreeNode *root, const std::vector<int> &voyage) {
    std::vector<int> flipped;
    std::function<bool(TreeNode * node, size_t & pos)> f;
    f = [&f, &flipped, &voyage](TreeNode *node, size_t &pos) -> bool {
        if (node == nullptr) {
            return true;
        }

        if (node->val != voyage[pos]) {
            flipped = std::vector<int>{-1};
            return false;
        }

        ++pos;
        if (pos < voyage.size() && node->left != nullptr && node->left->val != voyage[pos]) {
            flipped.push_back(node->val);
            if (f(node->right, pos)) {
                return f(node->left, pos);
            }

            return false;
        }

        if (f(node->left, pos)) {
            return f(node->right, pos);
        }

        return false;
    };

    size_t pos = 0;
    f(root, pos);

    return flipped;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        std::vector<int> voyage{2, 1};
        std::vector<int> expected{-1};
        auto ret = flipMatchVoyage(r, voyage);
        assert(ret == expected);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        std::vector<int> voyage{1, 3, 2};
        std::vector<int> expected{1};
        auto ret = flipMatchVoyage(r, voyage);
        assert(ret == expected);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        std::vector<int> voyage{1, 2, 3};
        auto ret = flipMatchVoyage(r, voyage);
        assert(ret.empty());
        delete r;
    }
    return 0;
}
