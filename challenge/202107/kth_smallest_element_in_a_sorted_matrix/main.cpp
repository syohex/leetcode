#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>

int kthSmallest(const std::vector<std::vector<int>> &matrix, int k) {
    struct Data {
        int value;
        size_t row;
        size_t column;
    };
    const auto cmp = [](const Data &a, const Data &b) { return a.value > b.value; };

    std::priority_queue<Data, std::vector<Data>, decltype(cmp)> pq(cmp);
    for (size_t i = 0; i < matrix.size(); ++i) {
        pq.push(Data{matrix[i][0], i, 0});
    }

    Data d;
    size_t cols = matrix[0].size();
    for (int i = 0; i < k; ++i) {
        d = pq.top();
        pq.pop();
        if (d.column + 1 < cols) {
            pq.push(Data{matrix[d.row][d.column + 1], d.row, d.column + 1});
        }
    }

    return d.value;
}

int main() {
    {
        std::vector<std::vector<int>> matrix{
            {1, 5, 9},
            {10, 11, 13},
            {12, 13, 15},
        };
        assert(kthSmallest(matrix, 8) == 13);
    }
    {
        std::vector<std::vector<int>> matrix{
            {-5},
        };
        assert(kthSmallest(matrix, 1) == -5);
    }
    return 0;
}
