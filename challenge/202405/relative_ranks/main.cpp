#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

std::vector<std::string> findRelativeRanks(const std::vector<int> &score) {
    auto v = score;
    std::sort(v.begin(), v.end(), std::greater<int>{});

    std::map<int, std::string> m;
    int len = score.size();
    for (int i = 0; i < len; ++i) {
        switch (i) {
        case 0:
            m[v[i]] = "Gold Medal";
            break;
        case 1:
            m[v[i]] = "Silver Medal";
            break;
        case 2:
            m[v[i]] = "Bronze Medal";
            break;
        default:
            m[v[i]] = std::to_string(i + 1);
        }
    }

    std::vector<std::string> ret;
    for (int s : score) {
        ret.push_back(m[s]);
    }

    return ret;
}

int main() {
    {
        std::vector<int> score{5, 4, 3, 2, 1};
        std::vector<std::string> expected{"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"};
        auto ret = findRelativeRanks(score);
        assert(ret == expected);
    }
    {
        std::vector<int> score{10, 3, 8, 9, 4};
        std::vector<std::string> expected{"Gold Medal", "5", "Bronze Medal", "Silver Medal", "4"};
        auto ret = findRelativeRanks(score);
        assert(ret == expected);
    }
    return 0;
}
