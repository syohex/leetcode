#include <cassert>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <limits>
#include <iostream>
#include <iomanip>

int findMaximumXORByBruteForce(const std::vector<int> &nums) {
    int ret = 0;
    int len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            ret = std::max(ret, nums[i] ^ nums[j]);
        }
    }
    return ret;
}

int findMaximumXORByTrie(const std::vector<int> &nums) {
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
    std::random_device rnd;
    std::mt19937 gen(rnd());
    std::uniform_int_distribution<> distrib(0, std::numeric_limits<int>::max());

    for (int num = 10; num <= 100'000; num *= 10) {
        std::vector<int> nums(num, 0);
        for (int i = 0; i < num; ++i) {
            nums[i] = distrib(gen);
        }

        auto start1 = std::chrono::system_clock::now();
        int ret1 = findMaximumXORByBruteForce(nums);
        auto end1 = std::chrono::system_clock::now();

        auto start2 = std::chrono::system_clock::now();
        int ret2 = findMaximumXORByTrie(nums);
        auto end2 = std::chrono::system_clock::now();

        auto diff1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
        auto diff2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
        const auto *msg = diff1 > diff2 ? "Trie is better" : "BruteForce is better";

        std::cout << "Size=" << std::setw(10) << num << "\t\tBrute Force: " << diff1.count() << "us\tTrie: " << diff2.count()
                  << "us\t" << msg << std::endl;

        if (ret1 != ret2) {
            printf("## ERROR!!\n");
        }
    }

    return 0;
}