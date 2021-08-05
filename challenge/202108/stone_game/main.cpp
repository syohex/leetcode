#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <tuple>

bool stoneGame(const std::vector<int> &piles) {
    using key_type = std::tuple<int, int, int, int, bool>;

    std::set<key_type> checked;
    std::function<bool(int left, int right, int alex, int lee, bool turn)> f;
    f = [&f, &piles, &checked](int left, int right, int alex, int lee, bool turn) -> bool {
        if (left == right) {
            return alex > lee;
        }

        auto key = key_type{left, right, alex, lee, turn};
        if (checked.find(key) != checked.end()) {
            return false;
        }

        if (turn) {
            if (f(left + 1, right, alex + piles[left], lee, !turn)) {
                return true;
            }
            if (f(left, right - 1, alex + piles[right], lee, !turn)) {
                return true;
            }
        } else {
            if (f(left + 1, right, alex, lee + piles[left], !turn)) {
                return true;
            }
            if (f(left, right - 1, alex, lee + piles[right], !turn)) {
                return true;
            }
        }

        checked.insert(key);
        return false;
    };

    int len = piles.size();
    return f(0, len - 1, 0, 0, true);
}

int main() {
    {
        std::vector<int> piles{5, 3, 4, 5};
        assert(stoneGame(piles));
    }
    {
        std::vector<int> piles{3, 2, 10, 4};
        assert(stoneGame(piles));
    }
    return 0;
}
