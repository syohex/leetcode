#include <cassert>
#include <string>
#include <vector>
#include <functional>
#include <set>
#include <algorithm>
#include <limits>

int minMutation(const std::string &start, const std::string &end, const std::vector<std::string> &bank) {
    const auto is_one_mutation = [](const std::string &a, const std::string &b) -> bool {
        for (int i = 0; i < 8; ++i) {
            bool ok = true;
            for (int j = 0; j < 8; ++j) {
                if (j == i) {
                    continue;
                }

                if (a[j] != b[j]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                return true;
            }
        }

        return false;
    };

    std::function<int(const std::string &gene, int steps, std::set<std::string> &checked)> f;
    f = [&](const std::string &gene, int steps, std::set<std::string> &checked) -> int {
        if (gene == end) {
            return steps;
        }

        int ret = std::numeric_limits<int>::max();
        for (const std::string &b : bank) {
            if (checked.find(b) != checked.end()) {
                continue;
            }

            if (is_one_mutation(gene, b)) {
                checked.insert(b);
                ret = std::min(ret, f(b, steps + 1, checked));
                checked.erase(b);
            }
        }

        return ret;
    };

    std::set<std::string> checked{start};
    int ret = f(start, 0, checked);
    return ret == std::numeric_limits<int>::max() ? -1 : ret;
}

int main() {
    {
        std::string start = "AACCGGTT";
        std::string end = "AACCGGTA";
        std::vector<std::string> bank{"AACCGGTA"};
        int ret = minMutation(start, end, bank);
        assert(ret == 1);
    }
    {
        std::string start = "AACCGGTT";
        std::string end = "AAACGGTA";
        std::vector<std::string> bank{"AACCGGTA", "AACCGCTA", "AAACGGTA"};
        int ret = minMutation(start, end, bank);
        assert(ret == 2);
    }
    {
        std::string start = "AAAAACCC";
        std::string end = "AACCCCCC";
        std::vector<std::string> bank{"AAAACCCC", "AAACCCCC", "AACCCCCC"};
        int ret = minMutation(start, end, bank);
        assert(ret == 3);
    }
    return 0;
}
