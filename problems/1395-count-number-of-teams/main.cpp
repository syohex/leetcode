#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

int numTeams(const std::vector<int> &rating) {
    int ret = 0;
    std::function<void(size_t index, const std::vector<int> &v)> f;
    f = [&f, &ret, &rating](size_t index, const std::vector<int> &v) {
        if (v.size() == 3) {
            if ((v[0] < v[1] && v[1] < v[2]) || (v[0] > v[1] && v[1] > v[2])) {
                ++ret;
            }
            return;
        }
        if (index >= rating.size()) {
            return;
        }

        if (v.size() == 0) {
            auto vv = v;
            vv.push_back(rating[index]);
            f(index + 1, vv);
            f(index + 1, v);
        } else if (v.size() == 1) {
            if (v[0] != rating[index]) {
                auto vv = v;
                vv.push_back(rating[index]);
                f(index + 1, vv);
            }
            f(index + 1, v);
        } else {
            if (v[0] < v[1]) {
                if (v[1] < rating[index]) {
                    auto vv = v;
                    vv.push_back(rating[index]);
                    f(index + 1, vv);
                }
            } else if (v[0] > v[1]) {
                if (v[1] > rating[index]) {
                    auto vv = v;
                    vv.push_back(rating[index]);
                    f(index + 1, vv);
                }
            }

            f(index + 1, v);
        }
    };

    f(0, std::vector<int>{});
    return ret;
}

int main() {
    {
        std::vector<int> input{2, 5, 3, 4, 1};
        assert(numTeams(input) == 3);
    }
    {
        std::vector<int> input{2, 1, 3};
        assert(numTeams(input) == 0);
    }
    {
        std::vector<int> input{1, 2, 3, 4};
        assert(numTeams(input) == 4);
    }
    return 0;
}
