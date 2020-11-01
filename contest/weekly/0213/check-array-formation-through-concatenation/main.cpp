#include <cassert>
#include <vector>
#include <set>
#include <cstdio>

bool canFormArray(const std::vector<int> &arr, const std::vector<std::vector<int>> &pieces) {
    size_t limit = arr.size();
    size_t pos = 0;
    std::set<size_t> s;
    while (true) {
        int val = arr[pos];

        bool found = false;
        for (size_t i = 0; i < pieces.size(); ++i) {
            if (s.find(i) != s.end()) {
                continue;
            }

            if (val == pieces[i][0]) {
                if (limit - pos < pieces[i].size()) {
                    continue;
                }

                bool found2 = true;
                for (size_t j = 1; j < pieces[i].size(); ++j) {
                    if (arr[pos + j] != pieces[i][j]) {
                        found2 = false;
                        break;
                    }
                }

                if (found2) {
                    pos += pieces[i].size();
                    if (pos == limit) {
                        return true;
                    }

                    found = true;
                    s.insert(i);
                }
            }
        }

        if (!found) {
            return false;
        }
    }

    return false;
}

int main() {
    {
        std::vector<int> arr{85};
        std::vector<std::vector<int>> pieces{
            {85},
        };
        assert(canFormArray(arr, pieces));
    }
    {
        std::vector<int> arr{15, 88};
        std::vector<std::vector<int>> pieces{
            {88},
            {15},
        };
        assert(canFormArray(arr, pieces));
    }
    {
        std::vector<int> arr{49, 18, 16};
        std::vector<std::vector<int>> pieces{
            {16, 18, 49},
        };
        assert(!canFormArray(arr, pieces));
    }
    {
        std::vector<int> arr{91, 4, 64, 78};
        std::vector<std::vector<int>> pieces{
            {78},
            {4, 64},
            {91},
        };
        assert(canFormArray(arr, pieces));
    }
    {
        std::vector<int> arr{1, 3, 5, 7};
        std::vector<std::vector<int>> pieces{
            {2, 4, 6, 8},
        };
        assert(!canFormArray(arr, pieces));
    }
    return 0;
}
