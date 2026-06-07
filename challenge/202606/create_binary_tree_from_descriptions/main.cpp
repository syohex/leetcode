#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

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

TreeNode *createBinaryTree(const vector<vector<int>> &descriptions) {
    set<int> parents;
    set<int> children;
    map<int, vector<pair<int, int>>> graph;

    for (const auto &d : descriptions) {
        parents.insert(d[0]);
        parents.insert(d[1]);
        children.insert(d[1]);
        graph[d[0]].emplace_back(d[1], d[2]);
    }

    for (auto it = parents.begin(); it != parents.end();) {
        if (children.find(*it) != children.end()) {
            it = parents.erase(it);
        } else {
            ++it;
        }
    }

    auto *root = new TreeNode(*parents.begin());
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        auto *node = q.front();
        q.pop();

        for (auto &[child, is_left] : graph[node->val]) {
            auto *child_node = new TreeNode(child);
            q.push(child_node);

            if (is_left == 1) {
                node->left = child_node;
            } else {
                node->right = child_node;
            }
        }
    }

    return root;
}

int main() {
    {
        vector<vector<int>> descriptions{
            {20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1},
        };
        auto *ret = createBinaryTree(descriptions);
        assert(ret->val == 50);
        assert(ret->left->val == 20);
        assert(ret->left->left->val == 15);
        assert(ret->left->right->val == 17);
        assert(ret->right->val == 80);
        assert(ret->right->left->val == 19);
        delete ret;
    }
    {
        vector<vector<int>> descriptions{
            {1, 2, 1},
            {2, 3, 0},
            {3, 4, 1},
        };
        auto *ret = createBinaryTree(descriptions);
        assert(ret->val == 1);
        assert(ret->left->val == 2);
        assert(ret->left->right->val == 3);
        assert(ret->left->right->left->val == 4);
        delete ret;
    }
    return 0;
}
