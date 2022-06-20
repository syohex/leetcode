#include <cassert>
#include <vector>
#include <string>
#include <cstdio>

class WordFilter {
  public:
    struct Trie {
        std::vector<Trie *> children_;
        int id_;

        Trie() : children_(27, nullptr), id_(-1) {
        }

        ~Trie() {
            for (auto *c : children_) {
                delete c;
            }
        }
    };

    WordFilter(const std::vector<std::string> &words) {
        for (size_t i = 0; i < words.size(); ++i) {
            for (size_t j = 0; j < words[i].size(); ++j) {
                std::string word = words[i] + "{";
                size_t len = word.size();

                Trie *cur = &trie_;
                cur->id_ = i;

                size_t limit = 2 * len - 1;
                for (size_t k = j; k < limit; ++k) {
                    size_t index = word[k % len] - 'a';
                    if (cur->children_[index] == nullptr) {
                        cur->children_[index] = new Trie();
                    }

                    cur = cur->children_[index];
                    cur->id_ = i;
                }
            }
        }
    }

    int f(const std::string &prefix, const std::string &suffix) {
        Trie *cur = &trie_;
        std::string word = suffix + "{" + prefix;

        for (char c : word) {
            size_t index = c - 'a';
            if (cur->children_[index] == nullptr) {
                return -1;
            }

            cur = cur->children_[index];
        }

        return cur->id_;
    }

    Trie trie_;
};

int main() {
    {
        std::vector<std::string> words{"apple"};
        WordFilter wf(words);

        assert(wf.f("a", "e") == 0);
        assert(wf.f("k", "e") == -1);
    }
    return 0;
}
