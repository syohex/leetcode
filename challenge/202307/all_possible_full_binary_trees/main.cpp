#include <cassert>
#include <vector>
#include <functional>
#include <map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int n, TreeNode *left, TreeNode *right) : val(0), left(left), right(right) {
    }
};

std::vector<TreeNode *> allPossibleFBT(int n) {
    std::map<int, std::vector<TreeNode *>> cache;
    std::function<std::vector<TreeNode *>(int n)> f;
    f = [&](int n) -> std::vector<TreeNode *> {
        if (n % 2 == 0) {
            return {};
        }

        if (n == 1) {
            return {new TreeNode()};
        }

        if (cache.find(n) != cache.end()) {
            return cache[n];
        }

        std::vector<TreeNode *> ret;
        for (int i = 1; i < n; i += 2) {
            auto lefts = f(i);
            auto rights = f(n - i - 1);

            for (auto *left : lefts) {
                for (auto *right : rights) {
                    ret.push_back(new TreeNode(0, left, right));
                }
            }
        }

        cache[n] = ret;
        return ret;
    };

    return f(n);
}

int main() {
    {
        auto ret = allPossibleFBT(7);
        assert(ret.size() == 5);
    }
    {
        auto ret = allPossibleFBT(3);
        assert(ret.size() == 1);
    }
    return 0;
}
