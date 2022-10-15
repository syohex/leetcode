#include <cassert>
#include <vector>

std::vector<int> findArray(const std::vector<int> &pref) {
    std::vector<int> ret{pref[0]};

    int v = pref[0];
    int len = pref.size();
    for (int i = 1; i < len; ++i) {
        int tmp = v ^ pref[i];
        ret.push_back(tmp);
        v ^= tmp;
    }
    return ret;
}

int main() {
    {
        std::vector<int> pref{5, 2, 0, 3, 1};
        std::vector<int> expected{5, 7, 2, 3, 2};
        auto ret = findArray(pref);
        assert(ret == expected);
    }
    {
        std::vector<int> pref{13};
        std::vector<int> expected{13};
        auto ret = findArray(pref);
        assert(ret == expected);
    }
    return 0;
}