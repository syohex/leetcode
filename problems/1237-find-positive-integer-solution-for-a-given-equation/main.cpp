#include <cassert>
#include <vector>
#include <cstdio>

enum FunctionID {
    kAdd = 1,
    kMul = 2,
};

struct CustomFunction {
    explicit CustomFunction(FunctionID function_id) : function_id_(function_id) {
    }
    int f(int x, int y) const {
        switch (function_id_) {
        case kAdd:
            return x + y;
        case kMul:
            return x * y;
        default:
            return 0;
        }
    }

    FunctionID function_id_;
};

std::vector<std::vector<int>> findSolution(const CustomFunction &customfunction, int z) {
    std::vector<std::vector<int>> ret;
    for (int x = 1; x < 1000; ++x) {
        for (int y = 1; y < 1000; ++y) {
            if (customfunction.f(x, y) == z) {
                ret.push_back(std::vector<int>{x, y});
            }
        }
    }
    return ret;
}

int main() {
    {
        CustomFunction c(kAdd);
        auto ret = findSolution(c, 5);
        std::vector<std::vector<int>> expected{
            {1, 4},
            {2, 3},
            {3, 2},
            {4, 1},
        };
        assert(ret == expected);
    }
    {
        CustomFunction c(kMul);
        auto ret = findSolution(c, 5);
        std::vector<std::vector<int>> expected{
            {1, 5},
            {5, 1},
        };
        assert(ret == expected);
    }
    return 0;
}
