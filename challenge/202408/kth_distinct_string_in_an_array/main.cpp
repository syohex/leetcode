#include <cassert>
#include <vector>
#include <string>
#include <string_view>
#include <map>

std::string kthDistinct(const std::vector<std::string> &arr, int k) {
    std::map<std::string_view, int> m;
    for (const auto &a : arr) {
        ++m[a];
    }

    int i = 0;
    for (const auto &a : arr) {
        if (m[a] == 1) {
            ++i;
            if (i == k) {
                return a;
            }
        }
    }

    return "";
}

int main() {
    {
        std::vector<std::string> arr{"d", "b", "c", "b", "c", "a"};
        auto ret = kthDistinct(arr, 2);
        assert(ret == "a");
    }
    {
        std::vector<std::string> arr{"aaa", "aa", "a"};
        auto ret = kthDistinct(arr, 1);
        assert(ret == "aaa");
    }
    {
        std::vector<std::string> arr{"a", "b", "a"};
        auto ret = kthDistinct(arr, 3);
        assert(ret == "");
    }
    return 0;
}
