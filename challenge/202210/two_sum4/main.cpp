#include <cassert>
#include <map>
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

bool findTarget(TreeNode *root, int k) {
    std::deque<TreeNode *> q;
    q.push_back(root);

    std::map<int, int> m;
    while (!q.empty()) {
        TreeNode *p = q.front();
        q.pop_front();

        ++m[p->val];
        if (p->left != nullptr) {
            q.push_back(p->left);
        }
        if (p->right != nullptr) {
            q.push_back(p->right);
        }
    }

    for (const auto &it : m) {
        int diff = k - it.first;
        auto it2 = m.find(diff);
        if (it2 == m.end()) {
            continue;
        }

        if (it.first != diff) {
            return true;
        }

        if (it.second >= 2) {
            return true;
        }
    }

    return false;
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(2);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(6);
        r->right->right = new TreeNode(7);
        assert(findTarget(r, 9));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(2);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(6);
        r->right->right = new TreeNode(7);
        assert(!findTarget(r, 28));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(1);
        r->right->right = new TreeNode(1);
        assert(!findTarget(r, 10));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(1);
        r->right->right = new TreeNode(5);
        assert(findTarget(r, 10));
        delete r;
    }

    return 0;
}