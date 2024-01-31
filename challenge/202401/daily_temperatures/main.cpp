#include <cassert>
#include <vector>

std::vector<int> dailyTemperatures(const std::vector<int> &temperatures)
{
    std::vector<int> ret(temperatures.size(), 0);
    std::vector<int> stack;

    for (size_t i = 0; i < temperatures.size(); ++i)
    {
        while (!stack.empty() && temperatures[stack.back()] < temperatures[i])
        {
            size_t v = stack.back();
            stack.pop_back();
            ret[v] = i - v;
        }

        stack.push_back(i);
    }
    return ret;
}

int main()
{
    {
        std::vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
        std::vector<int> expected{1, 1, 4, 2, 1, 1, 0, 0};
        auto ret = dailyTemperatures(temperatures);
        assert(ret == expected);
    }
    {
        std::vector<int> temperatures{30, 40, 50, 60};
        std::vector<int> expected{1, 1, 1, 0};
        auto ret = dailyTemperatures(temperatures);
        assert(ret == expected);
    }
    {
        std::vector<int> temperatures{30, 60, 90};
        std::vector<int> expected{1, 1, 0};
        auto ret = dailyTemperatures(temperatures);
        assert(ret == expected);
    }
    return 0;
}
