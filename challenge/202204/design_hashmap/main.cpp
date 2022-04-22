#include <cassert>
#include <algorithm>
#include <vector>
#include <list>

class MyHashMap {
  public:
    struct Data {
        int key;
        int value;

        bool operator==(const Data &other) const {
            return key == other.key && value == other.value;
        }
    };

    MyHashMap() : table_(4096) {
    }

    void put(int key, int value) {
        int index = hash(key);
        auto it = std::find_if(table_[index].begin(), table_[index].end(), [&key](const Data &d) { return key == d.key; });
        if (it == table_[index].end()) {
            table_[index].push_back({key, value});
        } else {
            it->value = value;
        }
    }

    int get(int key) {
        int index = hash(key);
        const auto it = std::find_if(table_[index].begin(), table_[index].end(), [&key](const Data &d) { return key == d.key; });
        if (it == table_[index].end()) {
            return -1;
        }

        return it->value;
    }

    void remove(int key) {
        int index = hash(key);
        const auto it = std::find_if(table_[index].begin(), table_[index].end(), [&key](const Data &d) { return d.key == key; });
        if (it != table_[index].end()) {
            table_[index].erase(it);
        }
    }

    int hash(int key) const {
        return key % 4096;
    }

    std::vector<std::list<Data>> table_;
};

int main() {
    {
        MyHashMap h;
        h.put(1, 1);
        h.put(2, 2);
        assert(h.get(1) == 1);
        assert(h.get(3) == -1);
        h.put(2, 1);
        assert(h.get(2) == 1);
        h.remove(2);
        assert(h.get(2) == -1);
    }
    return 0;
}