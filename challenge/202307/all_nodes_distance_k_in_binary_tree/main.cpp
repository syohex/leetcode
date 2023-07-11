#include <cassert>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <functional>
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

std::vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    std::function<void(TreeNode * node, std::map<TreeNode *, std::vector<TreeNode *>> & graph)> f;
    f = [&](TreeNode *node, std::map<TreeNode *, std::vector<TreeNode *>> &graph) {
        if (node == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            graph[node].push_back(node->left);
            graph[node->left].push_back(node);
        }

        if (node->right != nullptr) {
            graph[node].push_back(node->right);
            graph[node->right].push_back(node);
        }

        f(node->left, graph);
        f(node->right, graph);
    };

    std::map<TreeNode *, std::vector<TreeNode *>> graph;
    f(root, graph);

    std::deque<TreeNode *> q;
    q.push_back(target);

    std::set<TreeNode *> visited;
    visited.insert(target);

    for (int i = 0; i < k; ++i) {
        size_t len = q.size();

        for (size_t j = 0; j < len; ++j) {
            TreeNode *node = q.front();
            q.pop_front();

            for (TreeNode *next : graph[node]) {
                if (visited.find(next) == visited.end()) {
                    q.push_back(next);
                    visited.insert(next);
                }
            }
        }
    }

    std::vector<int> ret;
    while (!q.empty()) {
        ret.push_back(q.front()->val);
        q.pop_front();
    }

    return ret;
}

void check(const std::vector<int> &a, const std::vector<int> &b) {
    assert(std::set<int>(a.begin(), a.end()) == std::set<int>(b.begin(), b.end()));
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
        std::vector<int> expected{7, 4, 1};

        auto ret = distanceK(r, r->left, 2);
        check(ret, expected);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);

        auto ret = distanceK(r, r, 3);
        assert(ret.empty());

        delete r;
    }
    return 0;
}
