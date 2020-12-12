#include <cassert>
#include <functional>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

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

TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    std::map<size_t, std::vector<std::vector<TreeNode *>>> m;
    int max = -1;
    std::function<void(TreeNode * node, int depth, const std::vector<TreeNode *> &parents)> f;
    f = [&f, &m, &max](TreeNode *node, int depth, const std::vector<TreeNode *> &parents) {
        auto tmp = parents;
        tmp.push_back(node);

        if (node->left == nullptr && node->right == nullptr) {
            m[depth].push_back(tmp);
            max = std::max(max, depth);
            return;
        }

        if (node->left != nullptr) {
            f(node->left, depth + 1, tmp);
        }
        if (node->right != nullptr) {
            f(node->right, depth + 1, tmp);
        }
    };

    f(root, 0, std::vector<TreeNode *>{});

    auto &deepests = m[max];
    for (int i = static_cast<int>(deepests[0].size() - 1); i >= 0; --i) {
        bool ok = true;
        for (size_t j = 1; j < deepests.size(); ++j) {
            if (deepests[0][i] != deepests[j][i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return deepests[0][i];
        }
    }

    assert(!"never reach here");
    return nullptr;
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(5);
        r->left->left = new TreeNode(6);
        r->left->right = new TreeNode(2);
        r->left->right->left = new TreeNode(7);
        r->left->right->right = new TreeNode(4);
        r->right = new TreeNode(1);
        r->right->left = new TreeNode(0);
        r->right->right = new TreeNode(8);

        auto ret = subtreeWithAllDeepest(r);
        assert(ret == r->left->right);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        auto ret = subtreeWithAllDeepest(r);
        assert(ret == r);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(0);
        r->left = new TreeNode(1);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(2);

        auto ret = subtreeWithAllDeepest(r);
        assert(ret == r->right->left);
        delete r;
    }
    return 0;
}
