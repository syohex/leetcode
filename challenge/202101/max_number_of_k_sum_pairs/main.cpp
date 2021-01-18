#include <cassert>
#include <vector>
#include <map>

int maxOperations(const std::vector<int> &nums, int k) {
    std::map<int, int> m;
    for (int num : nums) {
        ++m[num];
    }

    int ret = 0;
    while (true) {
        bool update = false;

        for (auto &it : m) {
            if (it.second == 0) {
                continue;
            }

            int diff = k - it.first;
            if (it.first == diff) {
                if (it.second < 2) {
                    continue;
                }

                it.second -= 2;
            } else {
                if (m.find(diff) == m.end() || m[diff] == 0) {
                    continue;
                }

                --it.second;
                --m[diff];
            }

            update = true;
            ++ret;
        }

        if (!update) {
            break;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{1, 2, 3, 4};
        assert(maxOperations(input, 5) == 2);
    }
    {
        std::vector<int> input{3, 1, 3, 4, 3};
        assert(maxOperations(input, 6) == 1);
    }

    return 0;
}
