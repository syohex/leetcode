#include <cassert>
#include <map>
#include <cstdio>

class TwoSum {
  public:
    TwoSum() {
    }

    void add(int number) {
        ++m_[number];
    }

    bool find(int value) {
        for (auto it = m_.begin(); it != m_.end(); ++it) {
            int key = value - it->first;
            const auto itt = m_.find(key);
            if (itt == m_.end()) {
                continue;
            }

            if (it == itt) {
                if (it->second >= 2) {
                    return true;
                }

                continue;
            }

            return true;
        }

        return false;
    }

    std::map<int, int> m_;
};

int main() {
    {
        TwoSum t;
        t.add(1);
        t.add(3);
        t.add(5);
        assert(t.find(4));
        assert(!t.find(7));
    }
    {
        TwoSum t;
        t.add(0);
        assert(!t.find(0));
    }
    {
        TwoSum t;
        t.add(3);
        t.add(2);
        t.add(1);
        assert(!t.find(2));
        assert(t.find(3));
        assert(t.find(4));
        assert(t.find(5));
        assert(!t.find(6));
    }
    {
        TwoSum t;
        t.add(1);
        t.add(1);
        assert(!t.find(0));
        assert(!t.find(1));
        assert(t.find(2));

        t.add(-1);
        assert(t.find(0));
        assert(!t.find(1));
        assert(!t.find(-2));

        t.add(-1);
        assert(t.find(-2));
    }
    return 0;
}
