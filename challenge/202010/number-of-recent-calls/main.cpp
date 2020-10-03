#include <cassert>
#include <set>
#include <cstdio>

class RecentCounter {
  public:
    RecentCounter() {
    }

    int ping(int t) {
        s_.insert(t);

        for (auto it = s_.begin(); it != s_.end();) {
            if (t - *it > 3000) {
                it = s_.erase(it);
            } else {
                ++it;
            }
        }

        return static_cast<int>(s_.size());
    }

    std::set<int> s_;
};

int main() {
    RecentCounter r;
    assert(r.ping(1) == 1);
    assert(r.ping(100) == 2);
    assert(r.ping(3001) == 3);
    assert(r.ping(3002) == 3);
    return 0;
}
