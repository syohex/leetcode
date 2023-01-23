#include <cassert>
#include <vector>
#include <set>

int findJudge(int n, const std::vector<std::vector<int>> &trust) {
    std::vector<int> trusts(n, 0);
    std::vector<bool> has_trust_people(n, false);
    for (const auto &t : trust) {
        trusts[t[1] - 1] += 1;
        has_trust_people[t[0] - 1] = true;
    }

    for (int i = 0; i < n; ++i) {
        if (trusts[i] == n - 1 && !has_trust_people[i]) {
            return i + 1;
        }
    }

    return -1;
}

int main() {
    {
        int n = 2;
        std::vector<std::vector<int>> trust{{1, 2}};
        int ret = findJudge(n, trust);
        assert(ret == 2);
    }
    {
        int n = 3;
        std::vector<std::vector<int>> trust{{1, 3}, {2, 3}};
        int ret = findJudge(n, trust);
        assert(ret == 3);
    }
    {
        int n = 3;
        std::vector<std::vector<int>> trust{{1, 3}, {2, 3}, {3, 1}};
        int ret = findJudge(n, trust);
        assert(ret == -1);
    }
    {
        int n = 4;
        std::vector<std::vector<int>> trust{{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
        int ret = findJudge(n, trust);
        assert(ret == 3);
    }
    {
        int n = 3;
        std::vector<std::vector<int>> trust{{1, 2}, {2, 3}};
        int ret = findJudge(n, trust);
        assert(ret == -1);
    }
    return 0;
}
