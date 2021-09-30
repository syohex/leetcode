#include <cassert>
#include <vector>
#include <utility>

class MyCalendar {
  public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        for (const auto &p : v_) {
            if (start >= p.second) {
                continue;
            }

            if (start <= p.first) {
                if (end > p.first) {
                    return false;
                }
            }

            if (start >= p.first && start < p.second) {
                return false;
            }

            if (end > p.first && end < p.second) {
                return false;
            }
        }

        v_.push_back(std::make_pair(start, end));
        return true;
    }

    std::vector<std::pair<int, int>> v_;
};

int main() {
    //     {
    //         MyCalendar c;
    //         assert(c.book(10, 20));
    //         assert(!c.book(15, 25));
    //         assert(c.book(20, 30));
    //     }
    //     {
    //         MyCalendar c;
    //         assert(c.book(47, 50));
    //         assert(c.book(33, 41));
    //         assert(!c.book(39, 45));
    //         assert(!c.book(33, 42));
    //         assert(c.book(25, 32));
    //         assert(!c.book(26, 35));
    //         assert(c.book(19, 25));
    //         assert(c.book(3, 8));
    //         assert(c.book(8, 13));
    //         assert(!c.book(18, 27));
    //     }
    {
        MyCalendar c;
        assert(c.book(20, 29));
        assert(!c.book(13, 22));
        assert(c.book(44, 50));
        assert(c.book(1, 7));
        assert(!c.book(2, 10));
        assert(c.book(14, 20));
        assert(!c.book(19, 20));
        assert(c.book(36, 42));
        assert(!c.book(45, 50));
    }
    return 0;
}
