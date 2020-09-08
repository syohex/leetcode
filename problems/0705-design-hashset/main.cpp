#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>

class MyHashSet {
  public:
    MyHashSet() {
        constexpr size_t size = (MAX_VALUE + 64 - 1) / 64;
        data_ = new uint64_t[size];
        memset(data_, 0, sizeof(uint64_t) * size);
    }
    ~MyHashSet() {
        delete[] data_;
    }

    void add(int key) {
        size_t index = key / 64;
        size_t bit = key % 64;
        data_[index] |= 1ULL << bit;
    }

    void remove(int key) {
        size_t index = key / 64;
        size_t bit = key % 64;
        data_[index] &= ~(1ULL << bit);
    }

    bool contains(int key) {
        size_t index = key / 64;
        size_t bit = key % 64;
        return (data_[index] & (1ULL << bit)) != 0;
    }

    uint64_t *data_;
    static constexpr int MAX_VALUE = 1'000'000;
};

int main() {
    {
        MyHashSet m;
        m.add(1);
        m.add(2);
        assert(m.contains(1));
        assert(!m.contains(3));
        m.add(2);
        assert(m.contains(2));
        m.remove(2);
        assert(!m.contains(2));
    }
    return 0;
}
