#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <queue>

int openLock(const std::vector<std::string> &deadends, const std::string &target) {
    std::set<std::string> dead(deadends.begin(), deadends.end());
    if (dead.find("0000") != dead.end()) {
        return -1;
    }

    if (target == "0000") {
        return 0;
    }

    std::queue<std::string> q;
    q.push("0000");

    std::set<std::string> checked;

    int steps[2] = {-1, 1};
    int changes = 1;
    while (!q.empty()) {
        int queue_size = q.size();
        for (int i = 0; i < queue_size; ++i) {
            std::string s = q.front();
            q.pop();

            for (int j = 0; j < 4; ++j) {
                for (int step : steps) {
                    std::string tmp = s;
                    tmp[j] = (tmp[j] - '0' + step + 10) % 10 + '0';
                    if ((dead.find(tmp) != dead.end()) || (checked.find(tmp) != checked.end())) {
                        continue;
                    }
                    if (tmp == target) {
                        return changes;
                    }

                    checked.insert(tmp);
                    q.push(tmp);
                }
            }
        }

        ++changes;
    }

    return -1;
}

int main() {
    {
        std::vector<std::string> deadends{"0201", "0101", "0102", "1212", "2002"};
        assert(openLock(deadends, "0202") == 6);
    }
    {
        std::vector<std::string> deadends{"8888"};
        assert(openLock(deadends, "0009") == 1);
    }
    {
        std::vector<std::string> deadends{"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
        assert(openLock(deadends, "8888") == -1);
    }
    {
        std::vector<std::string> deadends{"0000"};
        assert(openLock(deadends, "8888") == -1);
    }
    return 0;
}
