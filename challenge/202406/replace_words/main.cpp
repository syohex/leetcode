#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <sstream>

std::string replaceWords(const std::vector<std::string> &dictionary, const std::string &sentence) {
    struct TrieNode {
        std::map<char, TrieNode *> table_;
        std::map<char, bool> finished_;

        ~TrieNode() {
            for (auto &it : table_) {
                delete it.second;
            }
        }
    };

    TrieNode root;
    for (const auto &word : dictionary) {
        TrieNode *node = &root;
        for (std::size_t i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (node->table_[c] == nullptr) {
                node->table_[c] = new TrieNode();
            }

            if (i == word.size() - 1) {
                node->finished_[c] = true;
            }

            node = node->table_[c];
        }
    }

    std::string ret;
    std::string tmp;
    std::stringstream ss(sentence);
    while (std::getline(ss, tmp, ' ')) {
        TrieNode *node = &root;
        std::string w;
        bool ok = false;
        for (char c : tmp) {
            if (node->table_[c] == nullptr) {
                break;
            }

            w.push_back(c);

            if (node->finished_[c]) {
                ok = true;
                break;
            }

            node = node->table_[c];
        }

        if (ok) {
            ret.append(w);
        } else {
            ret.append(tmp);
        }

        ret.push_back(' ');
    }

    if (!ret.empty()) {
        ret.pop_back();
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> dictionary{"cat", "bat", "rat"};
        std::string sentence = "the cattle was rattled by the battery";
        std::string expected = "the cat was rat by the bat";
        auto ret = replaceWords(dictionary, sentence);
        assert(ret == expected);
    }
    {
        std::vector<std::string> dictionary{"a", "b", "c"};
        std::string sentence = "aadsfasf absbs bbab cadsfafs";
        std::string expected = "a a b c";
        auto ret = replaceWords(dictionary, sentence);
        assert(ret == expected);
    }
    {
        std::vector<std::string> dictionary{"a", "aa", "aaa", "aaaa"};
        std::string sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
        std::string expected = "a a a a a a a a bbb baba a";
        auto ret = replaceWords(dictionary, sentence);
        assert(ret == expected);
    }
    return 0;
}
