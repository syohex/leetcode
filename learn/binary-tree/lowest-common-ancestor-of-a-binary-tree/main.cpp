#include <cassert>
#include <functional>
#include <map>
#include <stack>
#include <vector>

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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    const auto f = [](TreeNode *root, TreeNode *target) -> std::vector<TreeNode *> {
        // map: key: child_node, value: parent_node
        std::map<TreeNode *, TreeNode *> m;
        std::stack<TreeNode *> s;
        s.push(root);

        TreeNode *p = nullptr;
        while (true) {
            p = s.top();
            s.pop();

            if (p->val == target->val) {
                break;
            }

            if (p->left != nullptr) {
                m[p->left] = p;
                s.push(p->left);
            }
            if (p->right != nullptr) {
                m[p->right] = p;
                s.push(p->right);
            }
        }

        std::vector<TreeNode *> ancestors;
        while (true) {
            ancestors.push_back(p);

            auto it = m.find(p);
            if (it == m.end()) {
                break;
            }

            p = it->second;
        }

        return ancestors;
    };

    auto p_ancestors = f(root, p);
    auto q_ancestors = f(root, q);

    for (auto *qq : q_ancestors) {
        for (auto *pp : p_ancestors) {
            if (qq == pp) {
                return qq;
            }
        }
    }

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

        auto ret = lowestCommonAncestor(r, r->left, r->right);
        assert(ret == r);

        ret = lowestCommonAncestor(r, r->left, r->left->right->right);
        assert(ret == r->left);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);

        auto ret = lowestCommonAncestor(r, r, r->left);
        assert(ret == r);
        delete r;
    }
    return 0;
}
