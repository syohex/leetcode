#include <cassert>
#include <vector>
#include <set>

std::vector<int> sumZero(int n) {
    std::vector<int> ret;
    if (n % 2 == 1) {
        ret.push_back(0);
        --n;
    }

    size_t limit = n / 2;
    for (size_t i = 0; i < limit; ++i) {
        ret.push_back(i + 1);
        ret.push_back(-(i + 1));
    }

    return ret;
}

bool check(const std::vector<int> &v, size_t n) {
    std::set<int> s;
    int sum = 0;
    for (const auto i : v) {
        s.insert(i);
        sum += i;
    }

    return sum == 0 && v.size() == s.size() && s.size() == n;
}

int main() {
    {
        auto ret = sumZero(5);
        assert(check(ret, 5));
    }
    {
        auto ret = sumZero(3);
        assert(check(ret, 3));
    }
    {
        auto ret = sumZero(1);
        assert(check(ret, 1));
    }
    return 0;
}
