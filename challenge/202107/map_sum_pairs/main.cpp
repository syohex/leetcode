#include <cassert>
#include <string>
#include <map>

class MapSum {
  public:
    MapSum() {
    }

    void insert(const std::string &key, int val) {
        m_[key] = val;
    }

    int sum(const std::string &prefix) {
        int ret = 0;
        bool matched = false;
        for (const auto &it : m_) {
            const auto &key = it.first;
            if (key[0] != prefix[0]) {
                if (matched) {
                    break;
                }
                continue;
            }

            matched = true;
            if (key.find(prefix) == 0) {
                ret += it.second;
            }
        }

        return ret;
    }

    std::map<std::string, int> m_;
};

int main() {
    {
        MapSum m;
        m.insert("apple", 3);
        assert(m.sum("ap") == 3);
        m.insert("app", 2);
        assert(m.sum("ap") == 5);
    }
    return 0;
}
