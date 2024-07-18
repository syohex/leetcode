#include <cassert>
#include <functional>
#include <set>
#include <map>
#include <vector>
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

int countPairs(TreeNode *root, int distance) {
    std::function<void(TreeNode * node, TreeNode * prev, std::set<TreeNode *> & leaves,
                       std::map<TreeNode *, std::vector<TreeNode *>> & graph)>
        f;
    f = [&](TreeNode *node, TreeNode *prev, std::set<TreeNode *> &leaves,
            std::map<TreeNode *, std::vector<TreeNode *>> &graph) -> void {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            leaves.insert(node);
        }

        if (prev != nullptr) {
            graph[prev].push_back(node);
            graph[node].push_back(prev);
        }

        f(node->left, node, leaves, graph);
        f(node->right, node, leaves, graph);
    };

    std::set<TreeNode *> leaves;
    std::map<TreeNode *, std::vector<TreeNode *>> graph;
    f(root, nullptr, leaves, graph);

    int ret = 0;
    for (auto *leaf : leaves) {
        std::set<TreeNode *> visited{leaf};
        std::queue<TreeNode *> q;
        q.push(leaf);

        for (int i = 0; i <= distance; ++i) {
            int len = q.size();

            for (int i = 0; i < len; ++i) {
                auto *node = q.front();
                q.pop();

                visited.insert(node);

                if (leaves.find(node) != leaves.end() && node != leaf) {
                    ++ret;
                }

                for (auto *next : graph[node]) {
                    if (visited.find(next) == visited.end()) {
                        q.push(next);
                    }
                }
            }
        }
    }

    return ret / 2;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(3);

        int ret = countPairs(r, 3);
        assert(ret == 1);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(7);

        int ret = countPairs(r, 3);
        assert(ret == 2);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(7);
        r->left = new TreeNode(1);
        r->right = new TreeNode(4);
        r->left->left = new TreeNode(6);
        r->right->left = new TreeNode(5);
        r->right->right = new TreeNode(3);
        r->right->right->right = new TreeNode(2);

        int ret = countPairs(r, 3);
        assert(ret == 1);

        delete r;
    }
    return 0;
}