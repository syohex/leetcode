#include <cassert>
#include <vector>
#include <functional>
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

int amountOfTime(TreeNode *root, int start) {
    std::function<void(TreeNode * node, int parent, std::map<int, std::vector<int>> &graph)> f;
    f = [&f](TreeNode *node, int parent, std::map<int, std::vector<int>> &graph) {
        if (node == nullptr) {
            return;
        }

        if (parent != -1) {
            graph[parent].push_back(node->val);
            graph[node->val].push_back(parent);
        }

        f(node->left, node->val, graph);
        f(node->right, node->val, graph);
    };

    std::map<int, std::vector<int>> graph;
    f(root, -1, graph);

    std::deque<int> q;
    q.push_back(start);
    std::set<int> checked;
    checked.insert(start);

    int ret = -1;
    while (!q.empty()) {
        size_t len = q.size();
        for (size_t i = 0; i < len; ++i) {
            int node = q.front();
            q.pop_front();

            for (int next : graph[node]) {
                if (checked.find(next) == checked.end()) {
                    checked.insert(next);
                    q.push_back(next);
                }
            }
        }

        ++ret;
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(5);
        r->left->right = new TreeNode(4);
        r->left->right->left = new TreeNode(9);
        r->left->right->right = new TreeNode(2);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(10);
        r->right->right = new TreeNode(6);

        int ret = amountOfTime(r, 3);
        assert(ret == 4);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        int ret = amountOfTime(r, 1);
        assert(ret == 0);

        delete r;
    }
    return 0;
}
