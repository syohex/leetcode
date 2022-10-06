#include <cassert>
#include <string>
#include <map>

class TimeMap {
  public:
    TimeMap() {
    }

    void set(const std::string &key, const std::string &value, int timestamp) {
        m_[key][timestamp] = value;
    }

    std::string get(const std::string &key, int timestamp) {
        const auto &map = m_[key];
        const auto it = map.find(timestamp);
        if (it != map.end()) {
            return it->second;
        }

        for (auto it = map.rbegin(); it != map.rend(); ++it) {
            int t = it->first;
            if (t > timestamp) {
                continue;
            }

            return it->second;
        }

        return "";
    }

    std::map<std::string, std::map<int, std::string>> m_;
};

int main() {
    {
        TimeMap t;
        t.set("foo", "bar", 1);
        assert(t.get("foo", 1) == "bar");
        assert(t.get("foo", 3) == "bar");
        t.set("foo", "bar2", 4);
        assert(t.get("foo", 4) == "bar2");
        assert(t.get("foo", 5) == "bar2");
    }

    return 0;
}
