#include <cassert>
#include <vector>
#include <string>
#include <queue>
#include <map>

std::string kthDistinct(const std::vector<std::string> &arr, int k) {
    struct StrData {
        std::string str;
        size_t pos;
        int count;
    };
    std::map<std::string, StrData> m;
    for (size_t i = 0; i < arr.size(); ++i) {
        const auto &str = arr[i];
        if (m.find(str) == m.end()) {
            m[str] = StrData{str, i, 1};
        } else {
            ++m[str].count;
        }
    }

    const auto &cmp = [](const StrData &a, const StrData &b) -> bool { return a.pos < b.pos; };

    std::vector<StrData> v;
    for (const auto &it : m) {
        if (it.second.count == 1) {
            v.push_back(it.second);
        }
    }

    if (k > static_cast<int>(v.size())) {
        return "";
    }

    std::sort(v.begin(), v.end(), cmp);
    return v[k - 1].str;
}

int main() {
    {
        std::vector<std::string> arr{"d", "b", "c", "b", "c", "a"};
        assert(kthDistinct(arr, 2) == "a");
    }
    {
        std::vector<std::string> arr{"aaa", "aa", "a"};
        assert(kthDistinct(arr, 1) == "aaa");
    }
    {
        std::vector<std::string> arr{"a", "b", "a"};
        assert(kthDistinct(arr, 3) == "");
    }
    return 0;
}