#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <queue>

int openLock(const std::vector<std::string> &deadends, const std::string &target) {
    std::set<std::string> deadend(deadends.begin(), deadends.end());
    if (deadend.find("0000") != deadend.end()) {
        return -1;
    }

    std::queue<std::string> q;
    q.push("0000");

    std::set<std::string> checked;
    checked.insert("0000");

    std::vector<int> steps{-1, 1};
    int ret = 0;
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            std::string s = q.front();
            q.pop();

            if (s == target) {
                return ret;
            }

            for (int j = 0; j < 4; ++j) {
                for (int step : steps) {
                    std::string tmp = s;
                    tmp[j] = (tmp[j] - '0' + step + 10) % 10 + '0';
                    if (deadend.find(tmp) == deadend.end() && checked.find(tmp) == checked.end()) {
                        checked.insert(tmp);
                        q.push(tmp);
                    }
                }
            }
        }

        ++ret;
    }
    return -1;
}

int main() {
    {
        std::vector<std::string> deadends{"0201", "0101", "0102", "1212", "2002"};
        std::string target = "0202";
        int ret = openLock(deadends, target);
        assert(ret == 6);
    }
    {
        std::vector<std::string> deadends{"8888"};
        std::string target = "0009";
        int ret = openLock(deadends, target);
        assert(ret == 1);
    }

    {
        std::vector<std::string> deadends{"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
        std::string target = "8888";
        int ret = openLock(deadends, target);
        assert(ret == -1);
    }

    return 0;
}
