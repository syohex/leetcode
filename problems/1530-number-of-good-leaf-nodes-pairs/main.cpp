#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <utility>
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

int CountPairs(TreeNode *root, int distance) {
    struct DepthInfo {
        DepthInfo() : depth(0), leaves(0) {
        }
        explicit DepthInfo(int depth, int leaves) : depth(depth), leaves(leaves) {
        }
        int depth;
        int leaves;
    };

    int answer = 0;
    std::function<std::vector<DepthInfo>(TreeNode * node)> f;
    f = [&f, &answer, &distance](TreeNode *node) -> std::vector<DepthInfo> {
        std::vector<DepthInfo> ret;
        if (node->left == nullptr && node->right == nullptr) {
            ret.emplace_back(1, 1);
            return ret;
        }

        std::vector<DepthInfo> leftInfo;
        if (node->left != nullptr) {
            leftInfo = f(node->left);
        }

        std::vector<DepthInfo> rightInfo;
        if (node->right != nullptr) {
            rightInfo = f(node->right);
        }

        for (const auto &li : leftInfo) {
            for (const auto &ri : rightInfo) {
                int length = li.depth + ri.depth;
                if (length <= distance) {
                    answer += li.leaves * ri.leaves;
                }
            }
        }

        for (auto &&info : leftInfo) {
            if (info.depth + 1 < distance) {
                ret.emplace_back(info.depth + 1, info.leaves);
            }
        }
        for (auto &&info : rightInfo) {
            if (info.depth + 1 < distance) {
                ret.emplace_back(info.depth + 1, info.leaves);
            }
        }

        return ret;
    };

    (void)f(root);
    return answer;
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(3);
        tree->left->right = new TreeNode(4);
        assert(CountPairs(tree, 3) == 1);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(3);
        tree->left->left = new TreeNode(4);
        tree->left->right = new TreeNode(5);
        tree->right->left = new TreeNode(6);
        tree->right->right = new TreeNode(7);
        assert(CountPairs(tree, 3) == 2);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(100);
        assert(CountPairs(tree, 1) == 0);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(1);
        tree->right = new TreeNode(1);
        assert(CountPairs(tree, 2) == 1);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(15);
        tree->left = new TreeNode(66);
        tree->right = new TreeNode(55);

        tree->left->left = new TreeNode(97);
        tree->left->right = new TreeNode(60);
        tree->right->left = new TreeNode(12);
        tree->right->right = new TreeNode(56);

        // tree->left->left->left = nullptr;
        tree->left->left->right = new TreeNode(54);
        // tree->left->right->left = nullptr;
        tree->left->right->right = new TreeNode(49);
        // tree->right->left->left = nullptr;
        tree->right->left->right = new TreeNode(9);
        // tree->right->right->left = nullptr;
        // tree->right->right->right = nullptr;

        // tree->left->left->left->left = nullptr;
        // tree->left->left->left->right = nullptr;
        // tree->left->left->right->left = nullptr;
        tree->left->left->right->right = new TreeNode(90);
        assert(CountPairs(tree, 5) == 3);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(78);
        tree->left = new TreeNode(15);
        tree->right = new TreeNode(81);

        tree->left->left = new TreeNode(73);
        tree->left->right = new TreeNode(98);
        tree->right->left = new TreeNode(36);
        // tree->right->right = nullptr;

        tree->left->left->left = new TreeNode(30);
        // tree->left->left->right = nullptr;
        tree->left->right->left = new TreeNode(63);
        tree->left->right->right = new TreeNode(32);
        assert(CountPairs(tree, 6) == 6);
        delete tree;
    }
    {
        TreeNode *tree = new TreeNode(80);

        tree->left = new TreeNode(62);
        tree->right = new TreeNode(99);

        tree->left->left = new TreeNode(36);
        tree->left->right = new TreeNode(45);
        tree->right->left = new TreeNode(39);
        tree->right->right = new TreeNode(76);

        tree->left->left->left = new TreeNode(81);
        tree->left->left->right = new TreeNode(44);
        tree->left->right->left = new TreeNode(23);
        tree->left->right->right = new TreeNode(58);
        tree->right->left->left = new TreeNode(8);
        tree->right->left->right = new TreeNode(14);
        tree->right->right->left = new TreeNode(1);
        tree->right->right->right = new TreeNode(94);

        tree->left->left->left->left = new TreeNode(100);
        tree->left->left->left->right = new TreeNode(10);
        tree->left->left->right->left = new TreeNode(8);
        tree->left->left->right->right = new TreeNode(30);
        tree->left->right->left->left = new TreeNode(75);
        tree->left->right->left->right = new TreeNode(7);
        tree->left->right->right->left = new TreeNode(33);
        tree->left->right->right->right = new TreeNode(80);
        tree->right->left->left->left = new TreeNode(44);
        tree->right->left->left->right = new TreeNode(2);
        tree->right->left->right->left = new TreeNode(67);
        tree->right->left->right->right = new TreeNode(78);
        tree->right->right->left->left = new TreeNode(64);
        tree->right->right->left->right = new TreeNode(30);
        tree->right->right->right->left = new TreeNode(98);
        tree->right->right->right->right = new TreeNode(100);

        tree->left->left->left->left->left = new TreeNode(24);
        tree->left->left->left->left->right = new TreeNode(48);
        tree->left->left->left->right->left = new TreeNode(42);
        tree->left->left->left->right->right = new TreeNode(31);
        tree->left->left->right->left->left = new TreeNode(91);
        tree->left->left->right->left->right = new TreeNode(37);
        tree->left->left->right->right->left = new TreeNode(81);
        tree->left->left->right->right->right = new TreeNode(45);
        tree->left->right->left->left->left = new TreeNode(30);
        tree->left->right->left->left->right = new TreeNode(77);
        tree->left->right->left->right->left = new TreeNode(28);
        assert(CountPairs(tree, 8) == 122);
        delete tree;
    }
    return 0;
}
