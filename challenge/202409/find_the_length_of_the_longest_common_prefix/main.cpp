#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

int longestCommonPrefix(const std::vector<int> &arr1, const std::vector<int> &arr2) {
    struct TrieNode {
        TrieNode *children[10] = {};

        ~TrieNode() {
            for (TrieNode *child : children) {
                delete child;
            }
        }
    };

    struct Trie {
        TrieNode *root;

        Trie() : root(new TrieNode()) {
        }

        ~Trie() {
            delete root;
        }

        void insert(int n) {
            std::string s = std::to_string(n);
            TrieNode *p = root;
            for (char c : s) {
                int key = c - '0';
                if (p->children[key] == nullptr) {
                    p->children[key] = new TrieNode();
                }

                p = p->children[key];
            }
        }

        int find(int n) {
            std::string s = std::to_string(n);
            int len = 0;
            TrieNode *p = root;

            for (char c : s) {
                int key = c - '0';
                if (p->children[key] == nullptr) {
                    break;
                }

                ++len;
                p = p->children[key];
            }

            return len;
        }
    };

    Trie t;
    for (int n : arr1) {
        t.insert(n);
    }

    int ret = 0;
    for (int n : arr2) {
        ret = std::max(ret, t.find(n));
    }

    return ret;
}

int main() {
    {
        std::vector<int> arr1{1, 10, 100};
        std::vector<int> arr2{1000};
        int ret = longestCommonPrefix(arr1, arr2);
        assert(ret == 3);
    }
    {
        std::vector<int> arr1{1, 2, 3};
        std::vector<int> arr2{4, 4, 4};
        int ret = longestCommonPrefix(arr1, arr2);
        assert(ret == 0);
    }
    return 0;
}