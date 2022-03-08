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
    struct Data {
        int left = -1;
        int right = -1;
    };

    std::map<int, Data> graph;
    std::set<int> parents;
    for (const auto &desc : descriptions) {
        parents.insert(desc[0]);
        if (desc[2] == 1) {
            graph[desc[0]].left = desc[1];
        } else {
            graph[desc[0]].right = desc[1];
        }
    }

    int root = -1;
    for (int parent : parents) {
        bool is_child = false;
        for (const auto &it : graph) {
            if (it.second.left == parent || it.second.right == parent) {
                is_child = true;
                break;
            }
        }

        if (!is_child) {
            root = parent;
            break;
        }
    }

    TreeNode *ret = new TreeNode(root);
    std::deque<TreeNode *> q;
    q.push_back(ret);

    while (!q.empty()) {
        TreeNode *r = q.front();
        q.pop_front();

        if (graph.find(r->val) == graph.end()) {
            continue;
        }

        if (graph[r->val].left != -1) {
            r->left = new TreeNode(graph[r->val].left);
            q.push_back(r->left);
        }
        if (graph[r->val].right != -1) {
            r->right = new TreeNode(graph[r->val].right);
            q.push_back(r->right);
        }
    }

    return ret;
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