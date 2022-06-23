#include <cassert>
#include <vector>
#include <algorithm>
#include <queue>

int scheduleCourse(std::vector<std::vector<int>> &courses) {
    std::sort(courses.begin(), courses.end(), [](const std::vector<int> &a, const std::vector<int> &b) { return a[1] < b[1]; });

    std::priority_queue<int> q;
    int time = 0;
    for (const auto &course : courses) {
        if (time + course[0] <= course[1]) {
            time += course[0];
            q.push(course[0]);
        } else if (!q.empty() && course[0] < q.top()) {
            time += course[0] - q.top();
            q.pop();
            q.push(course[0]);
        }
    }

    return q.size();
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
    {
        std::vector<std::vector<int>> courses{{5, 5}, {4, 6}, {2, 6}};
        int ret = scheduleCourse(courses);
        assert(ret == 2);
    }
    {
        std::vector<std::vector<int>> courses{{7, 17}, {3, 12}, {10, 20}, {9, 10}, {5, 20}, {10, 19}, {4, 18}};
        int ret = scheduleCourse(courses);
        assert(ret == 4);
    }
    return 0;
}