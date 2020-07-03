#include <cassert>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::vector<int>> groupThePeople(const std::vector<int> &groupSizes) {
    std::vector<std::vector<int>> ret;
    std::map<int, std::vector<int>> m;

    for (size_t i = 0; i < groupSizes.size(); ++i) {
        int num = groupSizes[i];
        m[num].push_back(i);

        if (m[num].size() == num) {
            ret.push_back(m[num]);
            m[num].clear();
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> groupSizes{3, 3, 3, 3, 3, 1, 3};
        auto ret = groupThePeople(groupSizes);
        assert(ret.size() == 3);
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{5}) != ret.end()));
    }
    {
        std::vector<int> groupSizes{2, 1, 3, 3, 3, 2};
        auto ret = groupThePeople(groupSizes);
        assert(ret.size() == 3);
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{1}) != ret.end()));
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{0, 5}) != ret.end()));
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{2, 3, 4}) != ret.end()));
    }
    return 0;
}
