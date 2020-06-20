#include <cassert>
#include <vector>
#include <set>

std::vector<int> sumEvenAfterQueries(std::vector<int> &A, const std::vector<std::vector<int>> &queries) {
    std::set<size_t> evenSet;
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] % 2 == 0) {
            evenSet.insert(i);
        }
    }

    std::vector<int> ret;
    for (const auto &v : queries) {
        A[v[1]] += v[0];
        if (A[v[1]] % 2 == 0) {
            evenSet.insert(v[1]);
        } else {
            evenSet.erase(v[1]);
        }

        int sum = 0;
        for (auto index : evenSet) {
            sum += A[index];
        }

        ret.push_back(sum);
    }
    return ret;
}

int main() {
    {
        std::vector<int> input{1, 2, 3, 4};
        std::vector<std::vector<int>> queries{
            {1, 0},
            {-3, 1},
            {-4, 0},
            {2, 3},
        };
        auto ret = sumEvenAfterQueries(input, queries);
        assert((ret == std::vector<int>{8, 6, 2, 4}));
    }
    return 0;
}
