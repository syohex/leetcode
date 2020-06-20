#include <cassert>
#include <vector>
#include <set>
#include <cstdio>

std::vector<int> sumEvenAfterQueries(std::vector<int> &A, const std::vector<std::vector<int>> &queries) {
    std::set<size_t> evenSet;
    int sum = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] % 2 == 0) {
            evenSet.insert(i);
            sum += A[i];
        }
    }

    std::vector<int> ret;
    for (const auto &v : queries) {
        if (v[0] == 0) {
            ret.push_back(sum);
            continue;
        }

        auto it = evenSet.find(v[1]);
        int orig = 0;
        if (it != evenSet.end()) {
            orig = A[*it];
        }
        A[v[1]] += v[0];
        if (A[v[1]] % 2 == 0) {
            evenSet.insert(v[1]);
            if (it == evenSet.end()) {
                sum += A[v[1]];
            } else {
                sum += v[0];
            }
            ret.push_back(sum);
        } else {
            evenSet.erase(v[1]);
            sum -= orig;
            ret.push_back(sum);
        }
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
    {
        std::vector<int> input{1, 2, 0, 4};
        std::vector<std::vector<int>> queries{
            {5, 2},
            {0, 2},
            {3, 3},
            {2, 1},
        };
        auto ret = sumEvenAfterQueries(input, queries);
        assert((ret == std::vector<int>{6, 6, 2, 4}));
    }
    {
        std::vector<int> input{5, 4, 0, 2};
        std::vector<std::vector<int>> queries{
            {1, 1},
            {3, 1},
            {3, 3},
            {5, 1},
        };
        auto ret = sumEvenAfterQueries(input, queries);
        assert((ret == std::vector<int>{2, 10, 8, 0}));
    }
    return 0;
}
