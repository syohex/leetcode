#include <cassert>
#include <vector>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

std::vector<TreeNode *> generateTrees(int n) {
    std::function<std::vector<TreeNode *>(int, int)> f = [&](int start, int end) -> std::vector<TreeNode *> {
        if (start > end) {
            return {nullptr};
        }

        std::vector<TreeNode *> ret;
        for (int i = start; i <= end; ++i) {
            auto left_trees = f(start, i - 1);
            auto right_trees = f(i + 1, end);

            for (auto *left : left_trees) {
                for (auto *right : right_trees) {
                    ret.push_back(new TreeNode(i, left, right));
                }
            }
        }

        return ret;
    };

    return f(1, n);
}

int main() {
    {
        auto ret = generateTrees(3);
        assert(ret.size() == 5);
    }
    {
        auto ret = generateTrees(1);
        assert(ret.size() == 1);
    }
    return 0;
}
