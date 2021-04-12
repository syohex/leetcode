#include <cassert>
#include <vector>
#include <cmath>
#include <set>

std::vector<int> constructArray(int n, int k) {
    std::vector<int> ret;
    int start = 1;
    int end = n;

    while (start <= end) {
        if (k > 1) {
            if (k % 2 != 0) {
                ret.push_back(start);
                ++start;
            } else {
                ret.push_back(end);
                --end;
            }
            --k;
        } else {
            ret.push_back(start);
            ++start;
        }
    }

    return ret;
}

bool check(const std::vector<int> &v, int k) {
    std::set<int> s;
    for (size_t i = 0; i < v.size() - 1; ++i) {
        s.insert(std::abs(v[i + 1] - v[i]));
    }

    return s.size() == k;
}

int main() {
    {
        auto ret = constructArray(3, 1);
        assert(check(ret, 1));
    }
    {
        auto ret = constructArray(3, 2);
        assert(check(ret, 2));
    }
    {
        auto ret = constructArray(9, 5);
        assert(check(ret, 5));
    }
    return 0;
}
