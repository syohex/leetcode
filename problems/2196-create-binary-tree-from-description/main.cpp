#include <cassert>
#include <vector>
#include <map>
#include <set>
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

TreeNode *createBinaryTree(const std::vector<std::vector<int>> &descriptions) {
    std::map<int, TreeNode *> graph;
    std::map<int, int> parents;
    for (const auto &desc : descriptions) {
        TreeNode *parent;
        if (graph.find(desc[0]) != graph.end()) {
            parent = graph[desc[0]];
        } else {
            parent = new TreeNode(desc[0]);
        }

        graph[desc[0]] = parent;

        parents[desc[0]] += desc[0];
        parents[desc[1]] -= 3 * desc[1];

        TreeNode *child;
        if (graph.find(desc[1]) != graph.end()) {
            child = graph[desc[1]];
        } else {
            child = new TreeNode(desc[1]);
        }

        if (desc[2] == 1) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        graph[desc[1]] = child;
    }

    for (const auto &it : parents) {
        if (it.second > 0) {
            return graph[it.first];
        }
    }

    // never reach here
    return nullptr;
}

int main() {
    {
        std::vector<std::vector<int>> descriptions{{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
        auto ret = createBinaryTree(descriptions);
        assert(ret->val == 50);
        assert(ret->left->val == 20);
        assert(ret->left->left->val == 15);
        assert(ret->left->right->val == 17);
        assert(ret->right->val == 80);
        assert(ret->right->left->val == 19);
        delete ret;
    }
    {
        std::vector<std::vector<int>> descriptions{
            {1, 2, 1},
            {2, 3, 0},
            {3, 4, 1},
        };
        auto ret = createBinaryTree(descriptions);
        assert(ret->val == 1);
        assert(ret->left->val == 2);
        assert(ret->left->right->val == 3);
        assert(ret->left->right->left->val == 4);
        delete ret;
    }
    return 0;
}