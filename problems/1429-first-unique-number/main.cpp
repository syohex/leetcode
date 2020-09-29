#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <cstdio>

class FirstUnique {
  public:
    explicit FirstUnique(const std::vector<int> &nums) {
        std::set<int> indexs;
        std::map<int, int> m;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = i;
                continue;
            }

            indexs.insert(m[nums[i]]);
            indexs.insert(i);
        }

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (indexs.find(i) == indexs.end()) {
                v_.push_back(nums[i]);
                ++m_[nums[i]];
                continue;
            }

            m_[nums[i]] = 2;
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
        if (m_.find(value) != m_.end()) {
            ++m_[value];
            return;
        }

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
