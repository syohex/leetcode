#include <cassert>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <sstream>

static bool decideMinutes(std::map<int, int> &m, std::string &minute) {
    for (int i = 5; i >= 0; --i) {
        if (m.find(i) == m.end()) {
            continue;
        }

        if (m[i] == 0) {
            continue;
        }

        --m[i];
        for (int j = 9; j >= 0; --j) {
            if (m.find(j) != m.end() && m[j] > 0) {
                minute = std::to_string(i) + std::to_string(j);
                return true;
            }
        }

        ++m[i];
    }

    return false;
}

std::string largestTimeFromDigits(const std::vector<int> &A) {
    std::map<int, int> m;
    for (const auto i : A) {
        ++m[i];
    }

    std::string minute;
    std::stringstream ss;
    if (m.find(2) != m.end()) {
        --m[2];
        for (int i = 3; i >= 0; --i) {
            if (m.find(i) != m.end() && m[i] > 0) {
                --m[i];
                if (decideMinutes(m, minute)) {
                    ss << 2 << i << ":" << minute;
                    return ss.str();
                }
                ++m[i];
            }
        }

        ++m[2];
    }

    for (int i = 1; i >= 0; --i) {
        if (m.find(i) == m.end()) {
            continue;
        }

        if (m[i] == 0) {
            continue;
        }

        --m[i];
        for (int j = 9; j >= 0; --j) {
            if (m.find(j) != m.end() && m[j] > 0) {
                --m[j];
                if (decideMinutes(m, minute)) {
                    ss << i << j << ":" << minute;
                    return ss.str();
                }
                ++m[j];
            }
        }

        ++m[i];
    }

    return "";
}

int main() {
    {
        std::vector<int> input{1, 2, 3, 4};
        auto ret = largestTimeFromDigits(input);
        assert(ret == "23:41");
    }
    {
        std::vector<int> input{2, 0, 6, 6};
        auto ret = largestTimeFromDigits(input);
        assert(ret == "06:26");
    }
    {
        std::vector<int> input{5, 5, 5, 5};
        auto ret = largestTimeFromDigits(input);
        assert(ret == "");
    }
    return 0;
}
