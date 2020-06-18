#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

int numTeams(const std::vector<int> &rating) {
    int ret = 0;
    std::function<void(size_t index, size_t count, int a, int b, int c)> f;
    f = [&f, &ret, &rating](size_t index, size_t count, int a, int b, int c) {
        if (index >= rating.size()) {
            return;
        }
        if (rating.size() - index + count < 3) {
            return;
        }

        if (count == 0) {
            f(index + 1, 1, rating[index], 0, 0);
            f(index + 1, 0, 0, 0, 0);
        } else if (count == 1) {
            if (a != rating[index]) {
                f(index + 1, 2, a, rating[index], 0);
            }
            f(index + 1, 1, a, 0, 0);
        } else {
            if (a < b) {
                if (b < rating[index]) {
                    ++ret;
                }
            } else if (a > b) {
                if (b > rating[index]) {
                    ++ret;
                }
            }

            f(index + 1, 2, a, b, 0);
        }
    };

    f(0, 0, 0, 0, 0);
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
