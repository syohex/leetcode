#include <cassert>
#include <set>

class MyCalendar {
  public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        std::pair<int, int> key{start, end};
        auto it = ranges_.lower_bound(key);
        if (it != ranges_.end() && it->first < end) {
            return false;
        }

        if (it != ranges_.begin()) {
            auto prev = std::prev(it);
            if (start < prev->second) {
                return false;
            }
        }

        ranges_.insert(key);
        return true;
    }

    std::set<std::pair<int, int>> ranges_;
};

int main() {
    {
        MyCalendar m;
        assert(m.book(10, 20));
        assert(!m.book(15, 25));
        assert(m.book(20, 30));
    }
    return 0;
}