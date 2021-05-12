#include <cassert>
#include <vector>

class NumMatrix {
  public:
    NumMatrix(std::vector<std::vector<int>> matrix) {
        matrix_ = std::vector<std::vector<int>>(matrix.size() + 1, std::vector<int>(matrix[0].size(), 0));

        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                matrix_[i + 1][j] = matrix_[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for (int i = col1; i <= col2; ++i) {
            ret += matrix_[row2 + 1][i] - matrix_[row1][i];
        }
        return ret;
    }

    std::vector<std::vector<int>> matrix_;
};

int main() {
    {
        std::vector<std::vector<int>> matrix{
            {3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5},
        };

        NumMatrix m(matrix);
        assert(m.sumRegion(2, 1, 4, 3) == 8);
        assert(m.sumRegion(1, 1, 2, 2) == 11);
        assert(m.sumRegion(1, 2, 2, 4) == 12);
    }
    return 0;
}
