#include <cassert>
#include <vector>
#include <string>
#include <map>

std::vector<std::string> removeSubfolders(const std::vector<std::string> &folder) {
    const auto to_directories = [](const std::string &s) -> std::vector<std::string> {
        std::vector<std::string> ret;
        std::string tmp;
        for (size_t i = 1; i < s.size(); ++i) {
            if (s[i] == '/') {
                ret.push_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(s[i]);
            }
        }

        ret.push_back(tmp);
        return ret;
    };

    struct Trie {
        bool is_terminated = false;
        std::map<std::string, Trie *> table;
        ~Trie() {
            for (auto it : table) {
                delete it.second;
            }
        }

        void insert(const std::vector<std::string> &dirs) {
            Trie *t = this;
            for (const auto &dir : dirs) {
                if (t->table.find(dir) == t->table.end()) {
                    t->table[dir] = new Trie();
                }

                t = t->table[dir];
            }

            t->is_terminated = true;
        }

        bool isSubFolder(const std::vector<std::string> &dirs) const {
            const Trie *t = this;
            for (const auto &dir : dirs) {
                if (t->is_terminated) {
                    return true;
                }
                t = t->table.at(dir);
            }

            return false;
        }
    };

    std::vector<std::vector<std::string>> v;
    for (const auto &f : folder) {
        v.push_back(to_directories(f));
    }

    Trie trie;
    for (const auto &dirs : v) {
        trie.insert(dirs);
    }

    std::vector<std::string> ret;
    for (size_t i = 0; i < folder.size(); ++i) {
        if (!trie.isSubFolder(v[i])) {
            ret.push_back(folder[i]);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> folder{"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
        std::vector<std::string> expected{"/a", "/c/d", "/c/f"};
        auto ret = removeSubfolders(folder);
        assert(ret == expected);
    }
    {
        std::vector<std::string> folder{"/a", "/a/b/c", "/a/b/d"};
        std::vector<std::string> expected{"/a"};
        auto ret = removeSubfolders(folder);
        assert(ret == expected);
    }
    {
        std::vector<std::string> folder{"/a/b/c", "/a/b/ca", "/a/b/d"};
        std::vector<std::string> expected{"/a/b/c", "/a/b/ca", "/a/b/d"};
        auto ret = removeSubfolders(folder);
        assert(ret == expected);
    }
    return 0;
}