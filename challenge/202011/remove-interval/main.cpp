#include <cassert>
#include <vector>

std::vector<std::vector<int>> removeInterval(const std::vector<std::vector<int>> &intervals, const std::vector<int> &toBeRemoved) {
    std::vector<std::vector<int>> ret;
    for (const auto &interval : intervals) {
        if (interval[1] <= toBeRemoved[0] || interval[0] >= toBeRemoved[1]) {
            ret.push_back(interval);
        } else if (interval[0] < toBeRemoved[0]) {
            if (toBeRemoved[0] < interval[1]) {
                if (interval[1] <= toBeRemoved[1]) {
                    ret.emplace_back(std::vector<int>{interval[0], toBeRemoved[0]});
                } else {
                    ret.emplace_back(std::vector<int>{interval[0], toBeRemoved[0]});
                    ret.emplace_back(std::vector<int>{toBeRemoved[1], interval[1]});
                }
            }
        } else if (interval[0] == toBeRemoved[0]) {
            if (toBeRemoved[1] < interval[1]) {
                ret.emplace_back(std::vector<int>{toBeRemoved[1], interval[1]});
            }
        } else if (toBeRemoved[0] < interval[0] && interval[0] < toBeRemoved[1]) {
            if (toBeRemoved[1] < interval[1]) {
                ret.emplace_back(std::vector<int>{toBeRemoved[1], interval[1]});
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> intervals{
            {0, 2},
            {3, 4},
            {5, 7},
        };
        std::vector<int> toBeRemoved{1, 6};
        auto ret = removeInterval(intervals, toBeRemoved);
        assert(ret.size() == 2);
        assert((ret[0] == std::vector<int>{0, 1}));
        assert((ret[1] == std::vector<int>{6, 7}));
    }
    {
        std::vector<std::vector<int>> intervals{
            {0, 5},
        };
        std::vector<int> toBeRemoved{2, 3};
        auto ret = removeInterval(intervals, toBeRemoved);
        assert(ret.size() == 2);
        assert((ret[0] == std::vector<int>{0, 2}));
        assert((ret[1] == std::vector<int>{3, 5}));
    }
    {
        std::vector<std::vector<int>> intervals{
            {-5, -4}, {-3, -2}, {1, 2}, {3, 5}, {8, 9},
        };
        std::vector<int> toBeRemoved{-1, 4};
        auto ret = removeInterval(intervals, toBeRemoved);
        assert(ret.size() == 4);
        assert((ret[0] == std::vector<int>{-5, -4}));
        assert((ret[1] == std::vector<int>{-3, -2}));
        assert((ret[2] == std::vector<int>{4, 5}));
        assert((ret[3] == std::vector<int>{8, 9}));
    }
    {
        std::vector<std::vector<int>> intervals{
            {0, 100},
        };
        std::vector<int> toBeRemoved{0, 50};
        auto ret = removeInterval(intervals, toBeRemoved);
        assert(ret.size() == 1);
        assert((ret[0] == std::vector<int>{50, 100}));
    }
    return 0;
}
