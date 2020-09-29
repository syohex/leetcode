#include <cassert>
#include <vector>
#include <map>
#include <cstdio>

class FirstUnique {
  public:
    explicit FirstUnique(const std::vector<int> &nums) : v_(nums) {
        for (const int n : nums) {
            ++m_[n];
        }
    }

    int showFirstUnique() {
        for (const int n : v_) {
            if (m_[n] == 1) {
                return n;
            }
        }
        return -1;
    }

    void add(int value) {
        v_.push_back(value);
        ++m_[value];
    }

    std::vector<int> v_;
    std::map<int, int> m_;
};

int main() {
    {
        FirstUnique f(std::vector<int>{2, 3, 5});
        assert(f.showFirstUnique() == 2);
        f.add(5);
        assert(f.showFirstUnique() == 2);
        f.add(2);
        assert(f.showFirstUnique() == 3);
        f.add(3);
        assert(f.showFirstUnique() == -1);
    }
    {
        FirstUnique f(std::vector<int>{7, 7, 7, 7, 7, 7});
        assert(f.showFirstUnique() == -1);
        f.add(7);
        f.add(3);
        f.add(3);
        f.add(7);
        f.add(17);
        assert(f.showFirstUnique() == 17);
    }
    {
        FirstUnique f(std::vector<int>{809});
        assert(f.showFirstUnique() == 809);
        f.add(809);
        assert(f.showFirstUnique() == -1);
    }
    return 0;
}
