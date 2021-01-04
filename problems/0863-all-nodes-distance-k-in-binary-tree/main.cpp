#include <cassert>
#include <vector>
#include <map>
#include <functional>
#include <set>

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

std::vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    std::map<TreeNode *, std::vector<TreeNode *>> graph;
    std::function<void(TreeNode * node, TreeNode * parent)> f;
    f = [&f, &graph](TreeNode *node, TreeNode *parent) {
        if (node == nullptr) {
            return;
        }

        if (parent != nullptr) {
            graph[node].push_back(parent);
        }

        if (node->left != nullptr) {
            graph[node].push_back(node->left);
            f(node->left, node);
        }
        if (node->right != nullptr) {
            graph[node].push_back(node->right);
            f(node->right, node);
        }
    };

    f(root, nullptr);

    std::vector<int> ret;
    std::function<void(TreeNode * node, int count, int k, TreeNode *from)> f2;
    f2 = [&f2, &ret, &graph](TreeNode *node, int count, int k, TreeNode *from) {
        if (count == k) {
            ret.push_back(node->val);
            return;
        }

        for (auto *n : graph[node]) {
            if (n != from) {
                f2(n, count + 1, k, node);
            }
        }
    };

    f2(target, 0, K, nullptr);
    return ret;
}

bool check(const std::vector<int> &got, const std::vector<int> &expected) {
    std::set<int> gs, es;
    for (int i : got) {
        gs.insert(i);
    }
    for (int i : expected) {
        es.insert(i);
    }

    return gs == es;
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
        r->right->right = new TreeNode(1);

        std::vector<int> expected{1, 4, 7};
        auto ret = distanceK(r, r->left, 2);
        assert(check(ret, expected));
        delete r;
    }
    return 0;
}