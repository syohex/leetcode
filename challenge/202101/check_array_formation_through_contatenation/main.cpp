#include <cassert>
#include <vector>
#include <set>
#include <cstdio>

bool canFormArray(const std::vector<int> &arr, const std::vector<std::vector<int>> &pieces) {
    size_t pos = 0;
    std::set<size_t> checked;
    while (pos < arr.size()) {
        bool found = false;
        for (size_t i = 0; i < pieces.size(); ++i) {
            if (checked.find(i) != checked.end()) {
                continue;
            }

            if (arr.size() - pos < pieces[i].size()) {
                continue;
            }

            bool ok = true;
            for (size_t j = 0; j < pieces[i].size(); ++j) {
                if (arr[pos + j] != pieces[i][j]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                found = true;
                pos += pieces[i].size();
                checked.insert(i);
                break;
            }
        }

        if (!found) {
            return false;
        }
    }

    return true;
}

int main() {
    {
        std::vector<int> arr{85};
        std::vector<std::vector<int>> pieces{{85}};
        assert(canFormArray(arr, pieces));
    }
    {
        std::vector<int> arr{15, 88};
        std::vector<std::vector<int>> pieces{{88}, {15}};
        assert(canFormArray(arr, pieces));
    }
    {
        std::vector<int> arr{49, 18, 16};
        std::vector<std::vector<int>> pieces{{16, 18, 49}};
        assert(!canFormArray(arr, pieces));
    }
    {
        std::vector<int> arr{91};
        std::vector<std::vector<int>> pieces{{78}, {4, 64}, {91}};
        assert(canFormArray(arr, pieces));
    }
    {
        std::vector<int> arr{1, 3, 5, 7};
        std::vector<std::vector<int>> pieces{{2, 4, 6, 8}};
        assert(!canFormArray(arr, pieces));
    }
    return 0;
}
