#include <cassert>
#include <functional>
#include <vector>
#include <list>

class MyHashSet {
  public:
    MyHashSet() : table_(TABLE_SIZE) {
    }

    void add(int key) {
        std::list<int> &lst = table_[hash(key)];

        auto it = std::find(lst.begin(), lst.end(), key);
        if (it != lst.end()) {
            return;
        }

        lst.push_back(key);
    }

    void remove(int key) {
        std::list<int> &lst = table_[hash(key)];

        auto it = std::find(lst.begin(), lst.end(), key);
        if (it == lst.end()) {
            return;
        }

        lst.erase(it);
    }

    bool contains(int key) {
        std::list<int> &lst = table_[hash(key)];

        auto it = std::find(lst.begin(), lst.end(), key);
        return it != lst.end();
    }

    size_t hash(int key) {
        return std::hash<int>{}(key) % TABLE_SIZE;
    }

    std::vector<std::list<int>> table_;
    static constexpr size_t TABLE_SIZE = 1024;
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
