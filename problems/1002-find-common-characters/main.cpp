#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::string> commonChars(const std::vector<std::string> &A) {
    std::vector<std::string> ret;
    if (A.empty()) {
        return ret;
    }

    const auto f = [](const std::string &s) -> std::map<char, int> {
        std::map<char, int> tmp;
        for (const auto c : s) {
            ++tmp[c];
        }

        return tmp;
    };

    auto base = f(A[0]);
    if (A.size() > 1) {
        for (auto it = A.begin() + 1; it < A.end(); ++it) {
            auto current = f(*it);
            for (auto bIt = base.begin(); bIt != base.end();) {
                auto cIt = current.find(bIt->first);
                if (cIt == current.end()) {
                    bIt = base.erase(bIt);
                } else {
                    if (bIt->second != cIt->second) {
                        bIt->second = std::min(bIt->second, cIt->second);
                    }

                    ++bIt;
                }
            }
        }
    }

    for (const auto b : base) {
        for (int i = 0; i < b.second; ++i) {
            ret.push_back(std::string(1, b.first));
        }
    }

    return ret;
}

bool check(const std::vector<std::string> &ret, const std::vector<std::string> &expected) {
    const auto f = [](const std::vector<std::string> &v) -> std::map<std::string, int> {
        std::map<std::string, int> tmp;
        for (const auto s : v) {
            ++tmp[s];
        }

        return tmp;
    };

    const auto r = f(ret);
    const auto e = f(expected);

    if (r.size() != e.size()) {
        return false;
    }

    for (const auto it : r) {
        const auto i = e.find(it.first);
        if (i == e.end() || i->second != it.second) {
            return false;
        }
    }

    return true;
}

int main() {
    {
        std::vector<std::string> input{"bella", "label", "roller"};
        const auto ret = commonChars(input);
        std::vector<std::string> expected{"e", "l", "l"};
        assert(check(ret, expected));
    }
    {
        std::vector<std::string> input{"cool", "lock", "cook"};
        const auto ret = commonChars(input);
        std::vector<std::string> expected{"c", "o"};
        assert(check(ret, expected));
    }
    return 0;
}
