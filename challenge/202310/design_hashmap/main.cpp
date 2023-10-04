#include <cassert>
#include <array>
#include <list>
#include <type_traits>

class MyHashMap {
  public:
    MyHashMap() {
    }

    void put(int key, int value) {
        int h = hash(key);

        for (auto &it : table_[h]) {
            if (it.first == key) {
                it.second = value;
                return;
            }
        }

        table_[h].push_back({key, value});
    }

    int get(int key) {
        int h = hash(key);

        for (auto &it : table_[h]) {
            if (it.first == key) {
                return it.second;
            }
        }

        return -1;
    }

    void remove(int key) {
        int h = hash(key);

        for (auto it = table_[h].begin(); it != table_[h].end(); ++it) {
            if (it->first == key) {
                table_[h].erase(it);
                return;
            }
        }
    }

    int hash(int key) const {
        return key % HASH_SIZE;
    }

    static constexpr int HASH_SIZE = 256;
    std::array<std::list<std::pair<int, int>>, HASH_SIZE> table_;
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
