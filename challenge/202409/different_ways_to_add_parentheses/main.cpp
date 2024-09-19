#include <cassert>
#include <vector>
#include <string>
#include <functional>
#include <map>
#include <cctype>
#include <algorithm>

std::vector<int> diffWaysToCompute(const std::string &expression) {
    std::map<std::pair<int, int>, std::vector<int>> cache;
    int len = expression.size();

    std::function<std::vector<int>(int left, int right)> f;
    f = [&](int left, int right) -> std::vector<int> {
        std::pair<int, int> key{left, right};
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        if (left == right && isdigit(expression[left])) {
            return {expression[left] - '0'};
        }

        if (left + 1 == right && isdigit(expression[left]) && isdigit(expression[right])) {
            return {(expression[left] - '0') * 10 + expression[right] - '0'};
        }

        std::vector<int> ret;
        for (int i = left; i <= right; ++i) {
            if (isdigit(expression[i])) {
                continue;
            }

            auto left_vals = f(left, i - 1);
            auto right_vals = f(i + 1, right);

            for (int v1 : left_vals) {
                for (int v2 : right_vals) {
                    switch (expression[i]) {
                    case '+':
                        ret.push_back(v1 + v2);
                        break;
                    case '-':
                        ret.push_back(v1 - v2);
                        break;
                    case '*':
                        ret.push_back(v1 * v2);
                        break;
                    }
                }
            }
        }

        cache[key] = ret;
        return ret;
    };

    return f(0, len - 1);
}

int main() {
    {
        std::string expression{"2-1-1"};
        std::vector<int> expected{0, 2};
        auto ret = diffWaysToCompute(expression);
        std::sort(ret.begin(), ret.end());
        assert(ret == expected);
    }
    {
        std::string expression{"2*3-4*5"};
        std::vector<int> expected{-34, -14, -10, -10, 10};
        auto ret = diffWaysToCompute(expression);
        std::sort(ret.begin(), ret.end());
        assert(ret == expected);
    }
    return 0;
}