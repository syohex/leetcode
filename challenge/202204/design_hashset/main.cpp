#include <cassert>
#include <vector>
#include <list>
#include <algorithm>

class MyHashSet {
  public:
    MyHashSet() : table_(512) {
    }

    void add(int key) {
        int k = hash(key);
        const auto it = std::find(table_[k].begin(), table_[k].end(), key);
        if (it == table_[k].end()) {
            table_[k].push_back(key);
        }
    }

    void remove(int key) {
        int k = hash(key);
        const auto it = std::find(table_[k].begin(), table_[k].end(), key);
        if (it != table_[k].end()) {
            table_[k].erase(it);
        }
    }

    bool contains(int key) {
        int k = hash(key);
        const auto it = std::find(table_[k].begin(), table_[k].end(), key);
        return it != table_[k].end();
    }

    int hash(int key) {
        return key % 512;
    }

    std::vector<std::list<int>> table_;
};

int main() {
    {
        MyHashSet h;
        h.add(1);
        h.add(2);
        assert(h.contains(1));
        assert(!h.contains(3));
        h.add(2);
        assert(h.contains(2));
        h.remove(2);
        assert(!h.contains(2));
    }
    return 0;
}