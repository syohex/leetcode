#include <cassert>
#include <vector>
#include <list>
#include <cstdio>

class MyHashMap {
  public:
    struct Data {
        explicit Data(int key, int val) : key(key), val(val) {
        }
        int key;
        int val;
    };

    MyHashMap() : table_(1000) {
    }

    void put(int key, int value) {
        int hash_value = hash(key);
        for (auto &data : table_[hash_value]) {
            if (data.key == key) {
                data.val = value;
                return;
            }
        }

        table_[hash_value].emplace_back(key, value);
    }

    int get(int key) {
        for (const auto &data : table_[hash(key)]) {
            if (data.key == key) {
                return data.val;
            }
        }

        return -1;
    }

    void remove(int key) {
        auto &lst = table_[hash(key)];
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            if ((*it).key == key) {
                lst.erase(it);
                return;
            }
        }
    }

    int hash(int n) {
        return n % 1000;
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
