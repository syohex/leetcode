#include <cassert>
#include <vector>
#include <map>

bool canReorderDoubled(const std::vector<int> &arr) {
    std::map<int, int> m;
    for (int a : arr) {
        ++m[a];
    }

    for (auto &it : m) {
        int val = it.first;
        int count = it.second;

        for (int i = 0; i < count; ++i) {
            auto it2 = m.find(val * 2);
            if (it2 == m.end() || it2->second == 0) {
                continue;
            }

            --it.second;
            --it2->second;
        }
    }

    for (auto &it : m) {
        if (it.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    {
        std::vector<int> arr{3, 1, 3, 6};
        assert(!canReorderDoubled(arr));
    }
    {
        std::vector<int> arr{2, 1, 2, 6};
        assert(!canReorderDoubled(arr));
    }
    {
        std::vector<int> arr{4, -2, 2, -4};
        assert(canReorderDoubled(arr));
    }
    {
        std::vector<int> arr{1, 2, 4, 16, 8, 4};
        assert(!canReorderDoubled(arr));
    }
    return 0;
}
