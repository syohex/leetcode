#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

int maxProfitAssignment(const std::vector<int> &difficulty, const std::vector<int> &profit, const std::vector<int> &worker) {
    std::vector<std::pair<int, int>> v{{0, 0}};
    for (std::size_t i = 0; i < difficulty.size(); ++i) {
        v.push_back({difficulty[i], profit[i]});
    }

    std::sort(v.begin(), v.end());

    for (std::size_t i = 1; i < v.size(); i++) {
        v[i].second = std::max(v[i].second, v[i - 1].second);
    }

    int ret = 0;
    for (int w : worker) {
        int left = 0;
        int right = v.size() - 1;
        int p = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid].first <= w) {
                left = mid + 1;
                p = std::max(p, v[mid].second);
            } else {
                right = mid - 1;
            }
        }

        ret += p;
    }

    return ret;
}

int main() {
    {
        std::vector<int> difficulty{2, 4, 6, 8, 10};
        std::vector<int> profit{10, 20, 30, 40, 50};
        std::vector<int> worker{4, 5, 6, 7};

        int ret = maxProfitAssignment(difficulty, profit, worker);
        assert(ret == 100);
    }
    {
        std::vector<int> difficulty{85, 47, 57};
        std::vector<int> profit{24, 66, 99};
        std::vector<int> worker{40, 25, 25};

        int ret = maxProfitAssignment(difficulty, profit, worker);
        assert(ret == 0);
    }
    {
        std::vector<int> difficulty{68, 35, 52, 47, 86};
        std::vector<int> profit{67, 17, 1, 81, 3};
        std::vector<int> worker{92, 10, 85, 84, 82};

        int ret = maxProfitAssignment(difficulty, profit, worker);
        assert(ret == 324);
    }
    {
        std::vector<int> difficulty{49, 49, 76, 88, 100};
        std::vector<int> profit{5, 8, 75, 89, 94};
        std::vector<int> worker{98, 72, 16, 27, 76};

        int ret = maxProfitAssignment(difficulty, profit, worker);
        assert(ret == 172);
    }
    {
        std::vector<int> difficulty{5, 50, 92, 21, 24, 70, 17, 63, 30, 53};
        std::vector<int> profit{68, 100, 3, 99, 56, 43, 26, 93, 55, 25};
        std::vector<int> worker{96, 3, 55, 30, 11, 58, 68, 36, 26, 1};

        int ret = maxProfitAssignment(difficulty, profit, worker);
        assert(ret == 765);
    }
    return 0;
}
