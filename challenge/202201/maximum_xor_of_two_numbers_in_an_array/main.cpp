#include <cassert>
#include <vector>
#include <algorithm>

int findMaximumXOR(const std::vector<int> &nums) {
    struct TrieNode {
        TrieNode *bits[2];

        TrieNode() : bits{nullptr, nullptr} {
        }
    };

    TrieNode *root = new TrieNode();

    for (int num : nums) {
        TrieNode *node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num & (1u << i)) != 0 ? 1 : 0;
            if (node->bits[bit] == nullptr) {
                node->bits[bit] = new TrieNode();
            }

            node = node->bits[bit];
        }
    }

    int ret = 0;
    for (int num : nums) {
        TrieNode *node = root;
        int val = 0;

        for (int i = 31; i >= 0; --i) {
            int bit = (num & (1 << i)) != 0 ? 1 : 0;
            int counter = (bit == 0) ? 1 : 0;
            if (node->bits[counter] != nullptr) {
                val |= (1 << i);
                node = node->bits[counter];
            } else {
                node = node->bits[bit];
            }
        }

        ret = std::max(ret, val);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{3, 10, 5, 25, 2, 8};
        assert(findMaximumXOR(nums) == 28);
    }
    {
        std::vector<int> nums{14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
        assert(findMaximumXOR(nums) == 127);
    }
    return 0;
}