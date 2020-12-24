#include <cassert>
#include <string>
#include <map>
#include <functional>

int numTilePossibilities(const std::string &tiles) {
    int ret = 0;

    std::function<void(size_t pos, size_t limit, const std::map<char, int> &m)> f;
    f = [&f, &ret](size_t pos, size_t limit, const std::map<char, int> &m) {
        if (pos == limit) {
            ++ret;
            return;
        }

        for (const auto &it : m) {
            if (it.second > 0) {
                auto tmp = m;
                --tmp[it.first];
                f(pos + 1, limit, tmp);
            }
        }
    };

    std::map<char, int> m;
    for (char c : tiles) {
        ++m[c];
    }

    for (size_t i = 1; i <= tiles.size(); ++i) {
        f(0, i, m);
    }

    return ret;
}

int main() {
    assert(numTilePossibilities("AAB") == 8);
    assert(numTilePossibilities("AAABBC") == 188);
    assert(numTilePossibilities("V") == 1);
    return 0;
}
