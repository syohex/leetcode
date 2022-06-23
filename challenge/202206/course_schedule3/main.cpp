#include <cassert>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

int scheduleCourse(std::vector<std::vector<int>> &courses) {
    std::sort(courses.begin(), courses.end(), [](const std::vector<int> &a, const std::vector<int> &b) { return a[1] < b[1]; });

    std::function<int(int time, int i, std::map<std::vector<int>, int> &cache)> f;
    f = [&](int time, int i, std::map<std::vector<int>, int> &cache) -> int {
        if (i == courses.size()) {
            return 0;
        }

        const std::vector<int> key{time, i};
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        int ret1 = 0;
        if (time + courses[i][0] <= courses[i][1]) {
            ret1 = 1 + f(time + courses[i][0], i + 1, cache);
        }

        int ret2 = f(time, i + 1, cache);
        cache[key] = std::max(ret1, ret2);
        return cache[key];
    };

    std::map<std::vector<int>, int> cache;
    return f(0, 0, cache);
}

int main() {
    {
        std::vector<std::vector<int>> courses{{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
        int ret = scheduleCourse(courses);
        assert(ret == 3);
    }
    {
        std::vector<std::vector<int>> courses{{1, 2}};
        int ret = scheduleCourse(courses);
        assert(ret == 1);
    }
    {
        std::vector<std::vector<int>> courses{{3, 2}, {4, 3}};
        int ret = scheduleCourse(courses);
        assert(ret == 0);
    }
    {
        std::vector<std::vector<int>> courses{{1, 2}, {2, 3}};
        int ret = scheduleCourse(courses);
        assert(ret == 2);
    }
    return 0;
}