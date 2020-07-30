#include <cassert>
#include <vector>
// 3, 7, 11 2^(n-1) + 2 a(n+1) = a(n) + 2^2, 3, 10, 21
// 6, 15, 24,
// 10, 26, 32
std::vector<int> distributeCandies(int candies, int num_people) {
    if (num_people == 1) {
        return std::vector<int>{candies};
    }

    std::vector<int> ret(num_people, 0);
    int given = 1;
    while (true) {
        for (int i = 0; i < num_people; ++i) {
            if (given > candies) {
                given = candies;
            }

            ret[i] += given;
            candies -= given;
            if (candies == 0) {
                return ret;
            }
            ++given;
        }
    }

    return ret;
}

int main() {
    assert((distributeCandies(7, 4) == std::vector<int>{1, 2, 3, 1}));
    assert((distributeCandies(10, 3) == std::vector<int>{5, 2, 3}));
    return 0;
}
