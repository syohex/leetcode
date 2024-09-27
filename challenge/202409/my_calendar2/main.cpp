#include <cassert>
#include <vector>
#include <algorithm>

class MyCalendarTwo {
  public:
    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        for (const auto &[s, e] : overlapped_) {
            if (isOverlapped(start, end, s, e)) {
                return false;
            }
        }

        for (const auto &[s, e] : bookings_) {
            if (isOverlapped(start, end, s, e)) {
                overlapped_.push_back({std::max(start, s), std::min(end, e)});
            }
        }

        bookings_.push_back({start, end});
        return true;
    }

    bool isOverlapped(int s1, int e1, int s2, int e2) const {
        return std::max(s1, s2) < std::min(e1, e2);
    }

    std::vector<std::pair<int, int>> bookings_;
    std::vector<std::pair<int, int>> overlapped_;
};

int main() {
    {
        MyCalendarTwo c;
        assert(c.book(10, 20));
        assert(c.book(50, 60));
        assert(c.book(10, 40));
        assert(!c.book(5, 15));
        assert(c.book(5, 10));
        assert(c.book(25, 55));
    }
    return 0;
}