#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cstdio>

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

int minimumOperations(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);

    int ret = 0;
    while (!q.empty()) {
        int len = q.size();
        vector<int> tmp;
        for (int i = 0; i < len; ++i) {
            auto *node = q.front();
            q.pop();

            tmp.push_back(node->val);
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }

        vector<int> orig = tmp;
        sort(tmp.begin(), tmp.end());

        unordered_map<int, int> m;
        for (size_t i = 0; i < tmp.size(); ++i) {
            m[orig[i]] = i;
        }

        for (size_t i = 0; i < tmp.size(); ++i) {
            if (tmp[i] != orig[i]) {
                int orig_index = m[tmp[i]];
                m[orig[i]] = orig_index;
                swap(orig[i], orig[orig_index]);
                ++ret;
            }
        }
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(7);
        r->left->right = new TreeNode(6);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(8);
        r->right->left->left = new TreeNode(9);
        r->right->right = new TreeNode(5);
        r->right->right->left = new TreeNode(10);

        int ret = minimumOperations(r);
        assert(ret == 3);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(7);
        r->left->right = new TreeNode(6);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(5);
        r->right->right = new TreeNode(4);

        int ret = minimumOperations(r);
        assert(ret == 3);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);

        int ret = minimumOperations(r);
        assert(ret == 0);

        delete r;
    }
    return 0;
}
