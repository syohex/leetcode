#include <cassert>
#include <vector>
#include <queue>

int leastInterval(const std::vector<char> &tasks, int n) {
    int freq[26] = {};

    for (char task : tasks) {
        ++freq[task - 'A'];
    }

    std::priority_queue<int> q;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] != 0) {
            q.push(freq[i]);
        }
    }

    int ret = 0;
    while (!q.empty()) {
        int cycle = n + 1;
        std::vector<int> tmp;

        int task_count = 0;
        while (cycle > 0 && !q.empty()) {
            if (q.top() >= 2) {
                tmp.push_back(q.top() - 1);
            }
            q.pop();
            ++task_count;
            --cycle;
        }

        for (int t : tmp) {
            q.push(t);
        }

        if (q.empty()) {
            ret += task_count;
        } else {
            ret += n + 1;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
        int ret = leastInterval(tasks, 2);
        assert(ret == 8);
    }
    {
        std::vector<char> tasks{'A', 'C', 'A', 'B', 'D', 'B'};
        int ret = leastInterval(tasks, 1);
        assert(ret == 6);
    }
    {
        std::vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
        int ret = leastInterval(tasks, 3);
        assert(ret == 10);
    }
    return 0;
}
