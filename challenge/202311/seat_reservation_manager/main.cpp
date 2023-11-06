#include <cassert>
#include <set>

class SeatManager {
  public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            seats_.insert(i);
        }
    }

    int reserve() {
        int ret = *seats_.begin();
        seats_.erase(seats_.begin());
        return ret;
    }

    void unreserve(int seatNumber) {
        seats_.insert(seatNumber);
    }

    std::set<int> seats_;
};

int main() {
    {
        SeatManager s(5);
        assert(s.reserve() == 1);
        assert(s.reserve() == 2);
        s.unreserve(2);
        assert(s.reserve() == 2);
        assert(s.reserve() == 3);
        assert(s.reserve() == 4);
        assert(s.reserve() == 5);
        s.unreserve(5);
        assert(s.reserve() == 5);
    }
    return 0;
}
