#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <random>

class RandomizedSet {
  public:
    RandomizedSet() : count_(0), engine_(dev_()) {
    }

    bool insert(int val) {
        if (m_.find(val) != m_.end()) {
            return false;
        }

        m_[val] = count_;
        if (v_.size() < count_ + 1) {
            v_.resize(count_ + 1);
        }
        v_[count_] = val;

        ++count_;
        return true;
    }

    bool remove(int val) {
        if (m_.find(val) == m_.end()) {
            return false;
        }

        size_t pos = m_[val];
        m_.erase(val);

        if (pos != count_ - 1) {
            std::swap(v_[pos], v_[count_ - 1]);
            m_[v_[pos]] = pos;
        }
        --count_;
        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<> dist(0, count_ - 1);
        return v_[dist(engine_)];
    }

    std::unordered_map<int, size_t> m_;
    std::vector<int> v_;
    size_t count_;
    std::random_device dev_;
    std::mt19937 engine_;
};

int main() {
    {
        RandomizedSet r;
        assert(r.insert(1));
        assert(!r.remove(2));
        assert(r.insert(2));
        int v = r.getRandom();
        assert(v == 1 || v == 2);
        assert(r.remove(1));
        assert(!r.insert(2));
        v = r.getRandom();
        assert(v == 2);
    }
    {
        RandomizedSet r;
        assert(r.insert(0));
        assert(r.insert(1));
        assert(r.remove(0));
        assert(r.insert(2));
        assert(r.remove(1));
        int v = r.getRandom();
        assert(v == 2);
    }
    {
        RandomizedSet r;
        assert(!r.remove(0));
        assert(!r.remove(0));
        assert(r.insert(0));
        int v = r.getRandom();
        assert(v == 0);
        assert(r.remove(0));
        assert(r.insert(0));
    }
    return 0;
}
